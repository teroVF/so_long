/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvieira <anvieira@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 19:14:23 by anvieira          #+#    #+#             */
/*   Updated: 2023/05/18 01:02:24 by anvieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	img_init(t_game *game)
{
	int	s;

	s = T_SIZE;
	game->img.player_t = mlx_xpm_file_to_image(game->mlx, PLAYER, &s, &s);
	if(!game->img.player_t)
		error_msg(game, PLAYER_XPM_ERR);
	game->img.floor_t = mlx_xpm_file_to_image(game->mlx, FLOOR_TILE, &s, &s);
	if(!game->img.player_t)
		error_msg(game, PLAYER_XPM_ERR);
	game->img.items_t = mlx_xpm_file_to_image(game->mlx, COLLECTIBLES, &s, &s);
	if(!game->img.player_t)
		error_msg(game, PLAYER_XPM_ERR);
	game->img.wall_t = mlx_xpm_file_to_image(game->mlx, TREE_TILE, &s, &s);
	if(!game->img.player_t)
		error_msg(game, PLAYER_XPM_ERR);
	game->img.exit_t = mlx_xpm_file_to_image(game->mlx, EXIT, &s, &s);
	if(!game->img.player_t)
		error_msg(game, PLAYER_XPM_ERR);
	game->img.friend_t = mlx_xpm_file_to_image(game->mlx, FRIENDS, &s, &s);
	if(!game->img.player_t)
		error_msg(game, PLAYER_XPM_ERR);
}

void	img_init_enemies(t_game *game)
{
	int	s;

	s = T_SIZE;
	game->img.enemy_t = mlx_xpm_file_to_image(game->mlx, ENEMIES, &s, &s);
	if(!game->img.player_t)
		error_msg(game, PLAYER_XPM_ERR);
	game->img.enemy_tt = mlx_xpm_file_to_image(game->mlx, ENEMY, &s, &s);
	if(!game->img.player_t)
		error_msg(game, PLAYER_XPM_ERR);
	game->img.enemy_tev = mlx_xpm_file_to_image(game->mlx, ENEMIES_EV, &s, &s);
	if(!game->img.player_t)
		error_msg(game, PLAYER_XPM_ERR);
}

void	render_map(t_game *game)
{
	int		x;
	int		y;

	x = 0;
	y = 0;
	while (game->map[y])
	{
		while (game->map[y][x])
		{
			if (game->map[y][x] == '1')
				mlx_put_image_to_window(game->mlx, game->win.win,
					game->img.wall_t, (70 + x * T_SIZE), (y * T_SIZE));
			else if (game->map[y][x] == '0')
				mlx_put_image_to_window(game->mlx, game->win.win,
					game->img.floor_t, (70 + x * T_SIZE), (y * T_SIZE));
			else if (game->map[y][x] == 'P')
				mlx_put_image_to_window(game->mlx, game->win.win,
					game->img.player_t, (70 + x * T_SIZE), (y * T_SIZE));
			else if (game->map[y][x] == 'C')
				mlx_put_image_to_window(game->mlx, game->win.win,
					game->img.items_t, (70 + x * T_SIZE), (y * T_SIZE));
			else if (game->map[y][x] == 'E')
				mlx_put_image_to_window(game->mlx, game->win.win,
					game->img.exit_t, (70 + x * T_SIZE), (y * T_SIZE));
			else if (game->map[y][x] == 'Y')
				mlx_put_image_to_window(game->mlx, game->win.win,
					game->img.enemy_t, (70 + x * T_SIZE), (y * T_SIZE));
		x++;
		}
	x = 0;
	y++;
	}
}

int	read_keys(int keypress, t_game *game)
{
	if (keypress == D || keypress == RIGHT)
		move_player_x(game, 1);
	else if (keypress == A || keypress == LEFT)
		move_player_x(game, -1);
	else if (keypress == S || keypress == DOWN)
		move_player_y(game, 1);
	else if (keypress == W || keypress == UP)
		move_player_y(game, -1);
	else if (keypress == ESC)
		end_program(game);
	if (game->elem.item == 0)
		enemy_turn(game);
	return (0);
}

void	render(t_game *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
		error_msg(game, MLX_INIT_ERR);
	game->move_n = 0;
	game->win.win = mlx_new_window(game->mlx,
			game->win.win_x, game->win.win_y, "SO_LONG");
	if (!game->win.win)
		error_msg(game, MLX_NEW_WINDOW_ERR);
	img_init(game);
	img_init_enemies(game);
	render_map(game);
	mlx_key_hook(game->win.win, read_keys, game);
	mlx_hook(game->win.win, 17, 1L << 0, end_program, game);
	mlx_loop(game->mlx);
}
