/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvieira <anvieira@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 04:35:21 by anvieira          #+#    #+#             */
/*   Updated: 2023/05/20 17:25:25 by anvieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	img_init(t_game *game)
{
	int	s;

	game->img.check = 1;
	s = T_SIZE;
	game->img.player_t = mlx_xpm_file_to_image(game->mlx, PLAYER, &s, &s);
	if (!game->img.player_t)
		error_msg(game, PLAYER_XPM_ERR);
	game->img.floor_t = mlx_xpm_file_to_image(game->mlx, FLOOR_TILE, &s, &s);
	if (!game->img.floor_t)
		error_msg(game, FLOOR_XPM_ERR);
	game->img.items_t = mlx_xpm_file_to_image(game->mlx, COLLECTIBLES, &s, &s);
	if (!game->img.items_t)
		error_msg(game, COLLECTIBLE_XPM_ERR);
	game->img.wall_t = mlx_xpm_file_to_image(game->mlx, TREE_TILE, &s, &s);
	if (!game->img.wall_t)
		error_msg(game, WALL_XPM_ERR);
	game->img.exit_t = mlx_xpm_file_to_image(game->mlx, EXIT, &s, &s);
	if (!game->img.exit_t)
		error_msg(game, EXIT_XPM_ERR);
	game->img.friend_t = mlx_xpm_file_to_image(game->mlx, FRIENDS, &s, &s);
	if (!game->img.friend_t)
		error_msg(game, FRIEND_XPM_ERR);
}

void	img_init_bonus(t_game *game)
{
	int	s;

	s = T_SIZE;
	game->img.enemy_t = mlx_xpm_file_to_image(game->mlx, ENEMIES, &s, &s);
	if (!game->img.enemy_t)
		error_msg(game, PLAYER_XPM_ERR);
	game->img.enemy_tt = mlx_xpm_file_to_image(game->mlx, ENEMY, &s, &s);
	if (!game->img.enemy_tt)
		error_msg(game, PLAYER_XPM_ERR);
	game->img.player_l = mlx_xpm_file_to_image(game->mlx, PLAYER_L, &s, &s);
	if (!game->img.player_l)
		error_msg(game, PLAYER_XPM_ERR);
	game->img.player_r = mlx_xpm_file_to_image(game->mlx, PLAYER_R, &s, &s);
	if (!game->img.player_l)
		error_msg(game, PLAYER_XPM_ERR);
}
