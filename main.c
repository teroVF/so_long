/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvieira <anvieira@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 00:57:15 by anvieira          #+#    #+#             */
/*   Updated: 2023/05/10 02:45:15 by anvieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	end_program(t_game *game)
{
	if (!game)
		return (0);
	if (game->mlx)
		mlx_destroy_display(game->mlx);
	if (game->win.win)
		mlx_destroy_window(game->mlx, game->win.win);
	if (game->map)
		ft_free_xy(game->map);
	if (game->map_valid)
		ft_free_xy(game->map_valid);
	free(game);
	return(0);
}

t_game *game_init(char *pwd)
{
	t_game *game;

	game = (t_game*) malloc(sizeof(t_game) * 1);
	if(!game)
		return (NULL);
	game->mlx = NULL;
	game->win.win = NULL;
	game->map = read_map(pwd);
	game->map_valid = read_map(pwd);
	ft_printf("%s\n", game->map[0]);
	if (game->map == NULL || game->map_valid == NULL)
		end_program(game);
	if (validate_map(game) == 0)
		end_program(game);
	return (game);
}

int main(int argc, char *argv[])
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
