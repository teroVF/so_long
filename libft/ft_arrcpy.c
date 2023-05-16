/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antero <antero@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 05:39:23 by antero            #+#    #+#             */
/*   Updated: 2023/05/15 06:16:00 by antero           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char **ft_arrcpy(char **str)
{
	int		i;
	char	**str_new;

	i = 0;
	while (str[i])
		i++;
	str_new = (char **) malloc(sizeof(char *) * (i + 1));
	if (!str_new)
		return (NULL);
	i = 0;
	while (str[i])
	{
		str_new[i] = ft_strdup(str[i]);
		printf(" vai: %s\n", str_new[i]);
		printf("vai: %s\n", str[i]);
		printf("%p\n", str_new[i +1]);
		i++;
	}
	str_new[i] = NULL;
	return (str_new);
}
