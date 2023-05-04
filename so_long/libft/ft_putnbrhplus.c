/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbrhplus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvieira <anvieira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 23:32:31 by anvieira          #+#    #+#             */
/*   Updated: 2022/12/24 00:37:00 by anvieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	ft_count16(unsigned int value)
{
	int	i;

	i = 0;
	if (value == 0)
		i++;
	while (value)
	{
		value /= 16;
		i++;
	}
	return (i);
}

int	ft_putnbrhplus(unsigned int value)
{
	char	*hex;
	int		n;

	n = ft_count16(value);
	hex = "0123456789ABCDEF";
	if (value >= 16)
		ft_putnbrhplus(value / 16);
	value = value % 16;
	if (value < 16)
		ft_putchar_ret(hex[value]);
	return (n);
}
