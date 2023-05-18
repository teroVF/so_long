/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvieira <anvieira@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 05:39:23 by antero            #+#    #+#             */
/*   Updated: 2023/05/18 02:58:09 by anvieira         ###   ########.fr       */
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
		i++;
	}
	str_new[i] = NULL;
	return (str_new);
}
