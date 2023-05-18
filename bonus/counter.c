/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   counter.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvieira <anvieira@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 23:54:39 by anvieira          #+#    #+#             */
/*   Updated: 2023/05/18 03:48:56 by anvieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void counter_init(t_game *game)
{
	int	s;

	s = T_SIZE;
	game->img.c00 = mlx_xpm_file_to_image(game->mlx, C_00, &s, &s);
	game->img.c01 = mlx_xpm_file_to_image(game->mlx, C_01, &s, &s);
	game->img.c02 = mlx_xpm_file_to_image(game->mlx, C_02, &s, &s);
	game->img.c03 = mlx_xpm_file_to_image(game->mlx, C_03, &s, &s);
	game->img.c04 = mlx_xpm_file_to_image(game->mlx, C_04, &s, &s);
	game->img.c05 = mlx_xpm_file_to_image(game->mlx, C_05, &s, &s);
	game->img.c06 = mlx_xpm_file_to_image(game->mlx, C_00, &s, &s);
	game->img.c07 = mlx_xpm_file_to_image(game->mlx, C_01, &s, &s);
	game->img.c08 = mlx_xpm_file_to_image(game->mlx, C_02, &s, &s);
	game->img.c09 = mlx_xpm_file_to_image(game->mlx, C_03, &s, &s);
    if(game->img.c00 == NULL || game->img.c01 == NULL || game->img.c02 == NULL)
        error_msg(game, );
    if(game->img.c03 == NULL || game->img.c04 == NULL || game->img.c05 == NULL)
        error_msg(game, );
    if(game->img.c06 == NULL || game->img.c07 == NULL || game->img.c08 == NULL
        || game->img.c09 == NULL)
        error_msg(game, );
}