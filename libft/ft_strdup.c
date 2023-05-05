/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvieira <anvieira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 14:02:24 by anvieira          #+#    #+#             */
/*   Updated: 2022/12/19 10:26:19 by anvieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char		*new;
	size_t		len;

	len = ft_strlen(s1) + 1;
	new = (char *) malloc(len);
	if (!new)
		return (0);
	ft_memcpy(new, s1, len);
	return (new);
}
