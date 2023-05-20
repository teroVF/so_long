/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemies_move.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvieira <anvieira@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 01:10:40 by antero            #+#    #+#             */
/*   Updated: 2023/05/19 03:05:05 by anvieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	move_enemy_x(t_game *game, int i, t_enemy *enemy)
{
	int		x;
	int		y;

	x = enemy->x;
	y = enemy->y;
	if (x == (game->py.x - i) && y == game->py.y)
		end_program(game);
	else if (game->map[y][x + i] == '0')
	{
		mlx_put_image_to_window(game->mlx, game->win.win,
			game->img.floor_t, (80 + x * T_SIZE), (y * T_SIZE));
		game->map[y][x] = '0';
		x += i;
		mlx_put_image_to_window(game->mlx, game->win.win,
			game->img.enemy_tt, (80 + x * T_SIZE), (y * T_SIZE));
		enemy->x = x;
		game->map[y][x] = 'Y';
	}
	else if (game->map[y][x + 1] == 'P')
		end_program(game);
}

void	move_enemy_y(t_game *game, int i, t_enemy *enemy)
{
	int		x;
	int		y;

	x = (*enemy).x;
	y = (*enemy).y;
	if (x == game->py.x && y == (game->py.y - i))
		end_program(game);
	else if (game->map[y + i][x] == '0')
	{
		mlx_put_image_to_window(game->mlx, game->win.win,
			game->img.floor_t, (80 + x * T_SIZE), (y * T_SIZE));
		game->map[y][x] = '0';
		y += i;
		mlx_put_image_to_window(game->mlx, game->win.win,
			game->img.enemy_tt, (80 + x * T_SIZE), (y * T_SIZE));
		enemy->y = y;
		game->map[y][x] = 'Y';
	}
}

void	enemy_move(t_game *game, t_enemy *enemy)
{
	int	move;

	move = rand_num(0, 4);
	if (move == 1)
		move_enemy_x(game, 1, enemy);
	if (move == 2)
		move_enemy_x(game, -1, enemy);
	if (move == 3)
		move_enemy_y(game, 1, enemy);
	if (move == 4)
		move_enemy_y(game, -1, enemy);
	if (move == 0)
		return ;
}

void	enemy_turn(t_game *game)
{
	t_enemy		*tmp;

	tmp = game->enemy;
	while (tmp != NULL)
	{
		enemy_move(game, tmp);
		tmp = tmp->next;
	}
}
