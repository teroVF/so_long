/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_validate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antero <antero@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 05:04:22 by antero            #+#    #+#             */
/*   Updated: 2023/05/15 06:09:52 by antero           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	fill_path(char **map, int x, int y, t_size s)
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

int	enemy_path(t_game *game)
{
	t_size	s;
	int		y;
	int		x;

	y = 0;
	x = 0;
	s.y = 0;
	game->map_valid = ft_arrcpy(game->map);
	printf("aqui: %s\n", game->map_valid[0]);
	printf("aqui: %s\n", game->map_valid[1]);
	while (game->map_valid[s.y] != NULL)
		s.y++;
	s.x = ft_strlen(game->map_valid[0]);

	player_position(game);
	fill_path(game->map_valid, game->py.x, game->py.y, s);

	while (game->map_valid[y])
	{
		while (game->map_valid[y][x])
		{
			if (game->map_valid[y][x] == 'C')
				return (0);
			x++;
		}
		y++;
		x = 0;
	}
	return (1);
}
