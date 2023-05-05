/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbrhminor.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvieira <anvieira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 23:41:42 by anvieira          #+#    #+#             */
/*   Updated: 2022/12/24 00:35:10 by anvieira         ###   ########.fr       */
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

int	ft_putnbrhminor(unsigned int value)
{
	char	*hex;
	int		n;

	n = ft_count16(value);
	hex = "0123456789abcdef";
	if (value >= 16)
		ft_putnbrhminor(value / 16);
	value = value % 16;
	if (value < 16)
		ft_putchar_ret(hex[value]);
	return (n);
}
