/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvieira <anvieira@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 02:58:37 by anvieira          #+#    #+#             */
/*   Updated: 2023/05/25 19:28:41 by anvieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static t_game	*game_init(char *pwd)
{
	t_game	*game;

	game = (t_game *) malloc(sizeof(t_game) * 1);
	if (!game)
		return (0);
	game->mlx = NULL;
	game->win.win = NULL;
	game->enemy = NULL;
	game->map = NULL;
	game->map_valid = NULL;
	game->map = read_map(pwd, game);
	game->map_valid = read_map(pwd, game);
	if (game->map == NULL || game->map_valid == NULL)
		error_msg(game, EMPTY_MAP_FILE);
	validate_map(game);
	return (game);
}

static int	valid_ber(char *map_file)
{
	size_t	i;

	i = ft_strlen(map_file) - 4;
	if (ft_strncmp(".ber", &map_file[i], 4) == 0)
		return (1);
	return (0);
}

int	main(int argc, char *argv[])
{
	t_game	*game;

	if (argc != 2)
		error_msg(NULL, INVALID_NBR_ARGS);
	if (argv[1] == NULL)
		error_msg(NULL, NULL_MAP);
	if (!valid_ber(argv[1]))
		error_msg(NULL, INVALID_MAP_FILE);
	game = game_init(argv[1]);
	config_game(game);
	render(game);
	return (0);
}
