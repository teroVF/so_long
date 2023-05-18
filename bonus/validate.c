/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvieira <anvieira@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 00:58:01 by anvieira          #+#    #+#             */
/*   Updated: 2023/05/18 01:46:14 by anvieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	fill_path(char **map, int x, int y, t_size s)
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
	t_size	s;
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
	ft_free_xy(game->map_valid);
	return (1);
}

static int	only_char(char **map)
{
	int		i;
	int		j;

	i = 1;
	j = 1;
	while (map[i])
	{
		while (map[i][j])
		{
			if (map[i][j] != '1' && map[i][j] != '0' && map[i][j] != 'C'
					&& map[i][j] != 'P' && map[i][j] != 'E' )
				return (0);
			j++;
		}
		i++;
		j = 0;
	}
	return (1);
}

static int	if_is_a_rect1(t_game *game)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	game->width = ft_strlen(game->map[0]);
	while (game->map[i])
	{
		if ((int) ft_strlen(game->map[i]) != game->width)
			return (0);
		i++;
	}
	game->height = i;
	i = 0;
	while (game->map[i])
	{
		if (i == 0 || game->map[i + 1] == NULL)
		{
			while (game->map[i][j] == '1')
				j++;
			if (j != game->width)
				return (0);
		}
		else
		{
			if (game->map[i][0] != '1' || game->map[i][game->width -1] != '1')
				return (0);
		}
		j = 0;
		i++;
	}
	return (1);
}

int	validate_map(t_game *game)
{
	if (if_is_a_rect1(game) == 0)
		error_msg(game, INVALID_FORMAT);
	if (only_char(game->map) == 0)
		error_msg(game, INVALID_ENTITY);
	if (if_valid_path(game) == 0)
		error_msg(game, INVALID_FORMAT);
	return (1);
}
