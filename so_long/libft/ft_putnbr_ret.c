/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_ret.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvieira <anvieira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 13:31:14 by anvieira          #+#    #+#             */
/*   Updated: 2022/11/30 22:02:38 by anvieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putnbr_ret(int num)
{
	int	n;

	n = 0;
	if (num == -2147483648)
	{
		n += ft_putnbr_ret(-214748364);
		n += ft_putchar_ret(8 + 48);
		return (n);
	}
	if (num < 0)
	{
		n += ft_putchar_ret('-');
		num *= -1;
	}
	if (num > 9)
	{
		n += ft_putnbr_ret(num / 10);
		n += ft_putchar_ret((num % 10) + 48);
	}
	else
		n += ft_putchar_ret((num + 48));
	return (n);
}
