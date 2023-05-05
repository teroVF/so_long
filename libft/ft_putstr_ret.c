/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_ret.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvieira <anvieira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 04:12:27 by anvieira          #+#    #+#             */
/*   Updated: 2022/12/23 23:52:50 by anvieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putstr_ret(char *s)
{
	int	i;
	int	n;

	if (s == NULL)
		return (ft_putstr_ret("(null)"));
	i = 0;
	n = 0;
	while (s[i] != '\0')
	{
		n += ft_putchar_ret(s[i]);
		i++;
	}
	return (n);
}
