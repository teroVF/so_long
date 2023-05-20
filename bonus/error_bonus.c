/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvieira <anvieira@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 03:05:54 by antero            #+#    #+#             */
/*   Updated: 2023/05/20 14:36:40 by anvieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	img_destruction(t_game *game)
{
	mlx_destroy_image(game->mlx, game->img.player_t);
	mlx_destroy_image(game->mlx, game->img.floor_t);
	mlx_destroy_image(game->mlx, game->img.items_t);
	mlx_destroy_image(game->mlx, game->img.wall_t);
	mlx_destroy_image(game->mlx, game->img.exit_t);
	mlx_destroy_image(game->mlx, game->img.friend_t);
	mlx_destroy_image(game->mlx, game->img.enemy_t);
	mlx_destroy_image(game->mlx, game->img.enemy_tt);
	mlx_destroy_image(game->mlx, game->img.player_l);
	mlx_destroy_image(game->mlx, game->img.player_r);
	mlx_destroy_image(game->mlx, game->img.c00);
	mlx_destroy_image(game->mlx, game->img.c01);
	mlx_destroy_image(game->mlx, game->img.c02);
	mlx_destroy_image(game->mlx, game->img.c03);
	mlx_destroy_image(game->mlx, game->img.c04);
	mlx_destroy_image(game->mlx, game->img.c05);
	mlx_destroy_image(game->mlx, game->img.c06);
	mlx_destroy_image(game->mlx, game->img.c07);
	mlx_destroy_image(game->mlx, game->img.c08);
	mlx_destroy_image(game->mlx, game->img.c09);
}

int	end_program(t_game *game)
{
	t_enemy		*tmp;

	if (!game)
		exit(EXIT_FAILURE);
	img_destruction(game);
	if (game->win.win)
		mlx_destroy_window(game->mlx, game->win.win);
	if (game->mlx)
	{
		mlx_destroy_display(game->mlx);
		free(game->mlx);
	}
	if (game->map)
		ft_free_xy(game->map);
	if (game->map_valid)
		ft_free_xy(game->map_valid);
	while (game->enemy != NULL)
	{
		tmp = game->enemy->next;
		free(game->enemy);
		game->enemy = tmp;
	}
	free(game);
	exit(EXIT_SUCCESS);
}

int	end_program_fail(t_game *game)
{
	if (!game)
		exit(EXIT_FAILURE);
	if (game->win.win)
		mlx_destroy_window(game->mlx, game->win.win);
	if (game->mlx)
	{
		mlx_destroy_display(game->mlx);
		free(game->mlx);
	}
	if (game->map)
		ft_free_xy(game->map);
	if (game->map_valid)
		ft_free_xy(game->map_valid);
	free(game);
	exit(EXIT_FAILURE);
}

void	error_msg(t_game *game, char *error_msg)
{
	ft_putstr_fd("Error\n", STDERR_FILENO);
	ft_putendl_fd(error_msg, STDERR_FILENO);
	end_program_fail(game);
}
