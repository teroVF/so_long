/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvieira <anvieira@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 21:06:12 by antero            #+#    #+#             */
/*   Updated: 2023/05/23 16:26:49 by anvieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	verify_item(t_game *game, int x, int y)
{
	if (game->map[y][x] == 'C')
	{
		game->elem.item--;
		game->map[y][x] = '0';
		if (game->elem.item == 0)
			enemies_animation(game);
	}
	else if (game->map[y][x] == 'E' && !game->elem.item)
	{
		ft_printf("you won\n");
		end_program(game);
	}
	else if (game->map[y][x] == 'Y')
		end_program(game);
}

int	if_a_valide_move(t_game *game, int i, char c)
{
	int	y;
	int	x;

	x = game->py.x;
	y = game->py.y;
	if (game->map[y][x + i] == '1' && c == 'h')
		return (0);
	else if (game->map[y + i][x] == '1' && c == 'v')
		return (0);
	return (1);
}

void	move_player_y(t_game *game, int i)
{
	int		x;
	int		y;

	x = game->py.x;
	y = game->py.y;
	if (if_a_valide_move(game, i, 'v') == 0)
		return ;
	if (game->map[y][x] == 'E')
		mlx_put_image_to_window(game->mlx, game->win.win,
			game->img.exit_t, (80 + x * T_SIZE), (y * T_SIZE));
	else
		mlx_put_image_to_window(game->mlx, game->win.win,
			game->img.floor_t, (80 + x * T_SIZE), (y * T_SIZE));
	y += i;
	mlx_put_image_to_window(game->mlx, game->win.win,
		game->img.player_t, (80 + x * T_SIZE), (y * T_SIZE));
	game->py.y = y;
	game->move_n++;
	ft_printf("%d\n", game->move_n);
	counter_plus_one(game);
	verify_item(game, x, y);
}

void	animation_playerx(t_game *game, int i, int x, int y)
{
	if (i == -1)
		mlx_put_image_to_window(game->mlx, game->win.win,
			game->img.player_l, (80 + x * T_SIZE), (y * T_SIZE));
	if (i == 1)
		mlx_put_image_to_window(game->mlx, game->win.win,
			game->img.player_r, (80 + x * T_SIZE), (y * T_SIZE));
}

void	move_player_x(t_game *game, int i)
{
	int		x;
	int		y;

	x = game->py.x;
	y = game->py.y;
	if (if_a_valide_move(game, i, 'h') == 0)
		return ;
	if (game->map[y][x] == 'E')
		mlx_put_image_to_window(game->mlx, game->win.win,
			game->img.exit_t, (80 + x * T_SIZE), (y * T_SIZE));
	else
		mlx_put_image_to_window(game->mlx, game->win.win,
			game->img.floor_t, (80 + x * T_SIZE), (y * T_SIZE));
	x += i;
	animation_playerx(game, i, x, y);
	game->py.x = x;
	game->move_n++;
	ft_printf("%d\n", game->move_n);
	counter_plus_one(game);
	verify_item(game, x, y);
}
