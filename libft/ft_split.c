/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antero <antero@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 15:12:19 by anvieira          #+#    #+#             */
/*   Updated: 2023/05/08 02:20:41 by antero           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	count_string(char const *s, char c)
{
	int	i;

	i = 1;
	while (*s)
	{
		if (*s == c)
		{
			i++;
			if (*(s - 1) == c)
				i--;
		}
		s++;
	}
	return (i);
}

static char	*word_dup(const char *str, int start, int finish)
{
	char	*word;
	int		i;

	i = 0;
	word = malloc((finish - start + 1) * sizeof(char));
	while (start < finish)
		word[i++] = str[start++];
	word[i] = '\0';
	return (word);
}

char	**ft_split(char const *s, char c)
{
	char	**str;
	size_t	i;
	size_t	j;
	int		start;

	i = 0;
	j = 0;
	start = -1;
	str = malloc((count_string(s, c) + 1) * sizeof(char *));
	if (!str || !s)
		return (0);
	while (i <= ft_strlen(s))
	{
		if (s[i] != c && start < 0)
			start = i;
		else if ((s[i] == c || i == ft_strlen(s)) && start >= 0)
		{
			str[j++] = word_dup(s, start, i);
			start = -1;
		}
		i++;
	}
	str[j] = NULL;
	return (str);
}
