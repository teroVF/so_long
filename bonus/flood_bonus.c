/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvieira <anvieira@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 04:13:40 by anvieira          #+#    #+#             */
/*   Updated: 2023/05/20 04:15:41 by anvieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	fill_path(char **map, int x, int y, t_siz s)
{
	if (y < 0 || x < 0 || y >= s.y || x >= s.x)
		return ;
	if (map[y][x] != '0' && map[y][x]
		!= 'P' && map[y][x] != 'C' && map[y][x] != 'E')
		return ;
	map[y][x] = 'X';
	fill_path(map, x + 1, y, s);
	fill_path(map, x - 1, y, s);
	fill_path(map, x, y + 1, s);
	fill_path(map, x, y - 1, s);
}

static int	check_validator(t_game *game)
{
	int		x;
	int		y;

	x = 0;
	y = 0;
	while (game->map_valid[y])
	{
		while (game->map_valid[y][x])
		{
			if (game->map_valid[y][x] == 'C'
				|| game->map_valid[y][x] == 'P' || game->map_valid[y][x] == 'E')
				return (0);
			x++;
		}
		y++;
		x = 0;
	}
	return (1);
}

int	if_valid_path(t_game *game)
{
	t_siz	s;

	s.y = 0;
	while (game->map_valid[s.y] != NULL)
		s.y++;
	s.x = ft_strlen(game->map_valid[0]);
	player_position(game);
	fill_path(game->map_valid, game->py.x, game->py.y, s);
	if (check_validator(game) == 0)
		return (0);
	ft_free_xy(game->map_valid);
	return (1);
}
