/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvieira <anvieira@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 21:06:12 by antero            #+#    #+#             */
/*   Updated: 2023/05/23 17:33:20 by anvieira         ###   ########.fr       */
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
	else if (game->map[y][x] == 'E' && !game->elem.item)
	{
		ft_printf("you won\n");
		end_program(game);
	}
}

int	if_a_valide_move(t_game *game, int i, char c)
{
	int	y;
	int	x;

	x = game->py.x;
	y = game->py.y;
	if ((game->map[y][x + i] == '1' || game->map[y][x + i] == 'E')
		&& c == 'h' && game->elem.item)
		return (0);
	else if ((game->map[y + i][x] == '1' || game->map[y + i][x] == 'E')
		&& c == 'v' && game->elem.item)
		return (0);
	return (1);
}

void	move_player_y(t_game *game, int i)
{
	int		x;
	int		y;

	x = game->py.x;
	y = game->py.y;
	ft_printf("entrou");
	ft_printf("x: %d, y: %d\n", x , y);
	if (if_a_valide_move(game, i, 'v') == 0)
		return ;
	mlx_put_image_to_window(game->mlx, game->win.win,
			game->img.floor_t, (x * T_SIZE), (y * T_SIZE));
	y += i;
	ft_printf("x: %d, y: %d\n", x , y);
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
