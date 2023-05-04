/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvieira <anvieira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 16:42:08 by anvieira          #+#    #+#             */
/*   Updated: 2022/12/23 23:31:57 by anvieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_formats(va_list something, const char *str, int i)
{
	int	n;

	n = 0;
	if (str[i +1] == '%')
		n += ft_putchar_ret('%');
	else if (str[i +1] == 'c')
		n += ft_putchar_ret(va_arg(something, int));
	else if (str[i +1] == 'd' || str[i +1] == 'i')
		n += ft_putnbr_ret(va_arg(something, int));
	else if (str[i +1] == 's')
		n += ft_putstr_ret(va_arg(something, char *));
	else if (str[i +1] == 'x')
		n += ft_putnbrhminor(va_arg(something, unsigned int));
	else if (str[i +1] == 'X')
		n += ft_putnbrhplus(va_arg(something, unsigned int));
	else if (str[i +1] == 'u')
		n += ft_putnbru_ret(va_arg(something, unsigned int));
	else if (str[i +1] == 'p')
		n += ft_putptr_ret(va_arg(something, void *), 1);
	return (n);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	int		n;
	va_list	arguments;

	va_start(arguments, str);
	i = 0;
	n = 0;
	while (str[i])
	{
		if (str[i] == '%')
			n += ft_formats(arguments, str, i++);
		else
			n += ft_putchar_ret(str[i]);
		i++;
	}
	va_end(arguments);
	return (n);
}
