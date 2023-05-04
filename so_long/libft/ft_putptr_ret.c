/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr_ret.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvieira <anvieira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 04:56:23 by anvieira          #+#    #+#             */
/*   Updated: 2022/12/23 23:52:14 by anvieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putptr_ret(void *ptr, int check)
{
	unsigned long long	ret;
	int					n;

	ret = (unsigned long long)ptr;
	n = 0;
	if (ptr == 0)
		return (n += ft_putstr_ret("(nil)"));
	if (check)
	{
		check = 0;
		n += ft_putstr_ret("0x");
	}
	if (ret > 15)
		n += ft_putptr_ret((void *)(ret / 16), check);
	n += ft_putchar_ret("0123456789abcdef"[ret % 16]);
	return (n);
}
