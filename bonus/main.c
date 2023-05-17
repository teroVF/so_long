/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antero <antero@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 00:57:15 by anvieira          #+#    #+#             */
/*   Updated: 2023/05/17 16:03:06 by antero           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"


void img_destruction(t_game *game)
{
	mlx_destroy_image(game->mlx, game->img.player_t);
	mlx_destroy_image(game->mlx, game->img.floor_t);
	mlx_destroy_image(game->mlx, game->img.wall_t);
	mlx_destroy_image(game->mlx, game->img.items_t);
	mlx_destroy_image(game->mlx, game->img.friend_t);
	mlx_destroy_image(game->mlx, game->img.exit_t);
	mlx_destroy_image(game->mlx, game->img.enemy_t);
	mlx_destroy_image(game->mlx, game->img.enemy_tt);
	mlx_destroy_image(game->mlx, game->img.enemy_tev);
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
	while(game->enemy != NULL)
	{
		tmp = game->enemy->next;
		free(game->enemy);
		game->enemy= tmp;
	}
	free(game);
	exit(EXIT_SUCCESS);
}

int	end_program_fail(t_game *game)
{
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
	free(game);
	exit(EXIT_FAILURE);
}

t_game	*game_init(char *pwd)
{
	t_game	*game;

	game = (t_game *) malloc(sizeof(t_game) * 1);
	if (!game)
		return (0);
	game->mlx = NULL;
	game->win.win = NULL;
	game->enemy = NULL;
	game->map = read_map(pwd);
	game->map_valid = read_map(pwd);
	if (game->map == NULL || game->map_valid == NULL)
		end_program(game);
	if (validate_map(game) == 0)
		end_program(game);
	return (game);
}

// static int	valid_ber(char *map_file)
// {
// 	size_t	i;

// 	i = ft_strlen(map_file) - 4;
// 	if (ft_strncmp(".ber", &map_file[i], 4) == 0)
// 		return (1);
// 	return (0);
// }

int	main(int argc, char *argv[])
{
	t_game	*game;
	if (argc < 2)
		return (EXIT_FAILURE);
	game = game_init(argv[1]);
	if (game == NULL)
		return (EXIT_FAILURE);
	if (config_game(game) == 0)
		return (EXIT_FAILURE);
	render(game);
	return (0);
}
