/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antero <antero@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 14:02:24 by anvieira          #+#    #+#             */
/*   Updated: 2023/05/17 03:15:18 by antero           ###   ########.fr       */
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
