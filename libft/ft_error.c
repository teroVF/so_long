/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvieira <anvieira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 15:05:55 by anvieira          #+#    #+#             */
/*   Updated: 2023/04/04 05:24:23 by anvieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_error(char *error_msg)
{
	int	i;

	i = ft_strlen(error_msg);
	write(1, "Error: ", 7);
	write(1, error_msg, i);
	write(1, "\n", 1);
	exit(EXIT_FAILURE);
}
