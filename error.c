/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antero <antero@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 03:05:54 by antero            #+#    #+#             */
/*   Updated: 2023/05/17 04:57:08 by antero           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	error_msg(t_game *game, char *error_msg)
{
	ft_putstr_fd("Error\n", STDERR_FILENO);
	ft_putendl_fd(error_msg, STDERR_FILENO);
	end_program_fail(game);
}
