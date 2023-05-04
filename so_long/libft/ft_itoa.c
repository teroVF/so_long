/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvieira <anvieira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 19:57:38 by anvieira          #+#    #+#             */
/*   Updated: 2022/12/19 10:26:57 by anvieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	ft_count10(int value)
{
	int	i;

	i = 0;
	if (value < 0)
		i++;
	if (value == 0)
		i++;
	while (value)
	{
		value /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int value)
{
	int		i;
	char	*str;
	long	n;

	n = value;
	i = ft_count10(n) + 1;
	str = (char *) malloc(i * sizeof(char));
	if (!str)
		return (NULL);
	str[i - 1] = '\0';
	if (!n)
		str[0] = '0';
	if (n < 0)
	{
		str[0] = '-';
		n = -n;
	}
	while (n && i >= 0)
	{
		str[i-- - 2] = n % 10 + 48;
		n /= 10;
	}
	if (!str)
		return (NULL);
	return (str);
}
