/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antero <antero@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 01:30:39 by antero            #+#    #+#             */
/*   Updated: 2023/05/06 01:50:48 by antero           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void count_collectibles (t_game *game)
{
    char **tmp;
    int     i;
    int     j;

    tmp = game->map;
    while (tmp[i][j])
    {
        while (tmp[i][j])
        {
            if(tmp[i][j] == "C")
            	game->collectibles++;
			j++;
        }
		i++;
		j = 0;
	}
}

//return 0 is a error, the program must finish if player or exit  not equal to 1.
void count_exit_and_start (t_game *game)
{
    char **tmp;
    int     i;
    int     j;

    tmp = game->map;
    while (tmp[i][j])
    {
        while (tmp[i][j])
        {
            if (tmp[i][j] == "E")
            	game->exit++;
            if (tmp[i][j] == "P")
				game->player++;
			j++;
        }
		i++;
		j = 0;
	}
	if (game->player != 1 || game->exit != 1)
		return 0;
}

void wh_window_calculate(t_game *game)
{
	int		i;
	i = 0;
	
	game->window_x = ft_strlen(game->map[1]);
	game->window_y = 0;
	while(game->map[i])
	{
		game->window_y++;
		i++;
	}
}