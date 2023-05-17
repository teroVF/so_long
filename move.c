/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antero <antero@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 21:06:12 by antero            #+#    #+#             */
/*   Updated: 2023/05/17 04:57:58 by antero           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	verify_item(t_game *game, int x, int y)
{
	if (game->map[y][x] == 'C')
	{
		game->elem.item--;
		game->map[y][x] = '0';
	}
	else if (game->map[y][x] == 'E')
	{
		if (!game->elem.item)
		{
			ft_printf("you won\n");
			end_program(game);
		}
		mlx_put_image_to_window(game->mlx, game->win.win,
			game->img.friend_t, (x * T_SIZE), (y * T_SIZE));
	}
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
			game->img.exit_t, (x * T_SIZE), (y * T_SIZE));
	else
		mlx_put_image_to_window(game->mlx, game->win.win,
			game->img.floor_t, (x * T_SIZE), (y * T_SIZE));
	y += i;
	mlx_put_image_to_window(game->mlx, game->win.win,
		game->img.player_t, (x * T_SIZE), (y * T_SIZE));
	game->py.y = y;
	game->move_n++;
	ft_printf("%d\n", game->move_n);
	verify_item(game, x, y);
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
			game->img.exit_t, (x * T_SIZE), (y * T_SIZE));
	else
		mlx_put_image_to_window(game->mlx, game->win.win,
			game->img.floor_t, (x * T_SIZE), (y * T_SIZE));
	x += i;
	mlx_put_image_to_window(game->mlx, game->win.win,
		game->img.player_t, (x * T_SIZE), (y * T_SIZE));
	game->py.x = x;
	game->move_n++;
	ft_printf("%d\n", game->move_n);
	verify_item(game, x, y);
}
