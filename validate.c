/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antero <antero@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 00:58:01 by anvieira          #+#    #+#             */
/*   Updated: 2023/05/06 01:30:30 by antero           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

//i starts at one because the first line and the last are only ones

void if_valid_path()
{}

static	int only_01CEP(char **map)
{
	int     i;
	int     j;
	
	i = 1;
	j = 1;

	while (map[i])
	{
		while(map[i][j])
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

static int  if_is_a_rect1(char **map)
{
	size_t		i;
	size_t		j;
	size_t  length;

	i = 0;
	j = 0;
	length = ft_strlen(map[0]);
	while (map[i])
	{
		if(ft_strlen(map[i]) != length)
			return (0);
		i++;
	}
	i = 0;
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
			if(map[i][0] != '1' || map[i][length -1] != '1')
				return (0);
		}
		j = 0;
		i++;
	}
	return (1);
}

char	validate_map(char **map)
{
	if(if_is_a_rect1(map) == 0)
		return (0);
	if(only_01CEP(map) == 0)
		return (0);
	if (if_valid_path)
		return (0);
	return (1);
}