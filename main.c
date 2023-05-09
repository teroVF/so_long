/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antero <antero@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 00:57:15 by anvieira          #+#    #+#             */
/*   Updated: 2023/05/09 15:14:06 by antero           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	end_program(t_game *game)
{
	if (!game)
		return (0);
	ft_printf("passei 1\n");
	if (game->mlx)
		mlx_destroy_display(game->mlx);
	ft_printf("passei 1\n");
	if (game->win.win)
		mlx_destroy_window(game->mlx, game->win.win);
	ft_printf("passei 1\n");
	if(game->map)
		ft_free_xy(game->map);
	ft_printf("passei 1\n");
	if (game->map_valid)
		ft_free_xy(game->map_valid);
	free(game);
	ft_printf("passei 1\n");
	return(0);
}

t_game *game_init(char *pwd)
{
	t_game *game;

	game = (t_game*) malloc(sizeof(t_game) * 1);
	if(!game)
		return (NULL);
	game->map = read_map(pwd);
	game->map_valid = read_map(pwd);
	if (game->map == NULL)
		end_program(game);
	if(validate_map(game->map) == 0 )
		end_program(game);
	config_game(game);
	render(game);
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
	config_game(game);
	render(game);
	return 0;
}
