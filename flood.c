/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvieira <anvieira@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 04:01:03 by anvieira          #+#    #+#             */
/*   Updated: 2023/05/19 04:06:19 by anvieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	fill_path(char **map, int x, int y, t_siz s)
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

int	if_valid_path(t_game *game)
{
	t_siz	s;
	int		y;
	int		x;

	y = 0;
	x = 0;
	s.y = 0;
	while (game->map_valid[s.y] != NULL)
		s.y++;
	s.x = ft_strlen(game->map_valid[0]);
	player_position(game);
	fill_path(game->map_valid, game->py.x, game->py.y, s);
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
