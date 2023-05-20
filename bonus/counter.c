/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   counter.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvieira <anvieira@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 23:54:39 by anvieira          #+#    #+#             */
/*   Updated: 2023/05/19 02:58:56 by anvieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	counter_img_init(t_game *game)
{
	int	s;

	s = T_SIZE;
	game->img.c00 = mlx_xpm_file_to_image(game->mlx, C_00, &s, &s);
	game->img.c01 = mlx_xpm_file_to_image(game->mlx, C_01, &s, &s);
	game->img.c02 = mlx_xpm_file_to_image(game->mlx, C_02, &s, &s);
	game->img.c03 = mlx_xpm_file_to_image(game->mlx, C_03, &s, &s);
	game->img.c04 = mlx_xpm_file_to_image(game->mlx, C_04, &s, &s);
	game->img.c05 = mlx_xpm_file_to_image(game->mlx, C_05, &s, &s);
	game->img.c06 = mlx_xpm_file_to_image(game->mlx, C_06, &s, &s);
	game->img.c07 = mlx_xpm_file_to_image(game->mlx, C_07, &s, &s);
	game->img.c08 = mlx_xpm_file_to_image(game->mlx, C_08, &s, &s);
	game->img.c09 = mlx_xpm_file_to_image(game->mlx, C_09, &s, &s);
	if (game->img.c00 == NULL || game->img.c01 == NULL || game->img.c02 == NULL)
		error_msg(game, COUNTER_XPM_ERR);
	if (game->img.c03 == NULL || game->img.c04 == NULL || game->img.c05 == NULL)
		error_msg(game, COUNTER_XPM_ERR);
	if (game->img.c06 == NULL || game->img.c07 == NULL || game->img.c08 == NULL
		|| game->img.c09 == NULL)
		error_msg(game, COUNTER_XPM_ERR);
}

void	counter_init(t_game *game)
{
	counter_img_init(game);
	mlx_put_image_to_window(game->mlx, game->win.win,
		game->img.c00, 0, 0);
	mlx_put_image_to_window(game->mlx, game->win.win,
		game->img.c00, 20, 0);
	mlx_put_image_to_window(game->mlx, game->win.win,
		game->img.c00, 40, 0);
	mlx_put_image_to_window(game->mlx, game->win.win,
		game->img.c00, 60, 0);
}

void	counter_number(t_game *game, int n, int x)
{
	if (n == 0)
		mlx_put_image_to_window(game->mlx, game->win.win, game->img.c00, x, 0);
	if (n == 1)
		mlx_put_image_to_window(game->mlx, game->win.win, game->img.c01, x, 0);
	if (n == 2)
		mlx_put_image_to_window(game->mlx, game->win.win, game->img.c02, x, 0);
	if (n == 3)
		mlx_put_image_to_window(game->mlx, game->win.win, game->img.c03, x, 0);
	if (n == 4)
		mlx_put_image_to_window(game->mlx, game->win.win, game->img.c04, x, 0);
	if (n == 5)
		mlx_put_image_to_window(game->mlx, game->win.win, game->img.c05, x, 0);
	if (n == 6)
		mlx_put_image_to_window(game->mlx, game->win.win, game->img.c06, x, 0);
	if (n == 7)
		mlx_put_image_to_window(game->mlx, game->win.win, game->img.c07, x, 0);
	if (n == 8)
		mlx_put_image_to_window(game->mlx, game->win.win, game->img.c08, x, 0);
	if (n == 9)
		mlx_put_image_to_window(game->mlx, game->win.win, game->img.c09, x, 0);
}

void	counter_plus_one(t_game *game)
{
	int		n;

	n = game->move_n;
	if (n == 0)
		return ;
	counter_number(game, n % 10, 60);
	n /= 10;
	if (n == 0)
		return ;
	counter_number(game, n % 10, 40);
	n /= 10;
	if (n == 0)
		return ;
	counter_number(game, n % 10, 20);
	n /= 10;
	if (n == 0)
		return ;
	counter_number(game, n % 10, 0);
}
