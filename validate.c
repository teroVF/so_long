/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvieira <anvieira@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 00:58:01 by anvieira          #+#    #+#             */
/*   Updated: 2023/05/20 14:58:20 by anvieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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

static int	verify_side(char **map, int length)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (map[i])
	{
		if (i == 0 || map[i + 1] == NULL)
		{
			while (map[i][j] == '1')
				j++;
			if (j != length)
				return (0);
		}
		else
		{
			if (map[i][0] != '1' || map[i][length -1] != '1')
				return (0);
		}
		j = 0;
		i++;
	}
	return (1);
}

static int	if_is_a_rect1(char **map)
{
	size_t		i;
	size_t		length;

	i = 0;
	length = ft_strlen(map[0]);
	while (map[i])
	{
		if (ft_strlen(map[i]) != length)
			return (0);
		i++;
	}
	if (verify_side(map, length) == 0)
		return (0);
	return (1);
}

int	validate_map(t_game *game)
{
	if (if_is_a_rect1(game->map) == 0)
		error_msg(game, INVALID_FORMAT);
	if (only_char(game->map) == 0)
		error_msg(game, INVALID_ENTITY);
	if (if_valid_path(game) == 0)
		error_msg(game, INVALID_FORMAT);
	return (1);
}
