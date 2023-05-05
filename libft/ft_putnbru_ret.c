/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbru_ret.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvieira <anvieira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 04:15:21 by anvieira          #+#    #+#             */
/*   Updated: 2022/12/24 00:38:13 by anvieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putnbru_ret(unsigned int value)
{
	int	i;

	i = 0;
	if (value >= 10)
	{
		i += ft_putnbru_ret(value / 10);
		value %= 10;
	}
	if (value < 10)
		i += ft_putchar_ret(value + '0');
	return (i);
}
