/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvieira <anvieira@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 16:34:20 by antero            #+#    #+#             */
/*   Updated: 2023/05/19 02:58:49 by anvieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	count_collectibles(t_game *game)
{
	char	**tmp;
	int		i;
	int		j;

	game->elem.item = 0;
	i = 0;
	j = 0;
	tmp = game->map;
	while (tmp[i] != NULL)
	{
		while (tmp[i][j])
		{
			if (tmp[i][j] == 'C')
				game->elem.item++;
			j++;
		}
		i++;
		j = 0;
	}
	if (game->elem.item < 1)
		return (0);
	return (1);
}

static int	count_exit_and_start(t_game *game)
{
	char	**tmp;
	int		i;
	int		j;

	game->elem.exit = 0;
	game->elem.py = 0;
	i = 0;
	j = 0;
	tmp = game->map;
	while (tmp[i] != NULL)
	{
		while (tmp[i][j])
		{
			if (tmp[i][j] == 'E')
				game->elem.exit++;
			if (tmp[i][j] == 'P')
				game->elem.py++;
			j++;
		}
		i++;
		j = 0;
	}
	if (game->elem.py != 1 || game->elem.exit != 1)
		return (0);
	return (1);
}

static void	window_xy_init(t_game *game)
{
	int		i;

	i = 0;
	game->win.win_x = ft_strlen(game->map[1]) * T_SIZE + 80;
	game->win.win_y = 0;
	while (game->map[i])
		i++;
	game->win.win_y = i * T_SIZE;
}

void	player_position(t_game *game)
{
	char	**tmp;
	int		x;
	int		y;

	x = 1;
	y = 1;
	tmp = game->map;
	while (tmp[y] != NULL)
	{
		while (tmp[y][x])
		{
			if (tmp[y][x] == 'P')
			{
				game->py.x = x;
				game->py.y = y;
			}
			x++;
		}
		x = 0;
		y++;
	}
}

int	config_game(t_game *game)
{
	if (count_collectibles(game) == 0)
		error_msg(game, NO_COLLECTIBLES);
	if (count_exit_and_start(game) == 0)
		error_msg(game, INVALID_SETUP);
	window_xy_init(game);
	generate_enemies(game);
	return (1);
}
