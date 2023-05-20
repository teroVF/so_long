/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_enemies.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvieira <anvieira@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 02:59:08 by antero            #+#    #+#             */
/*   Updated: 2023/05/20 18:22:11 by anvieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	enemy_init(t_game *game, int x, int y)
{
	t_enemy		*tmp;
	t_enemy		*tmp_game;

	tmp_game = game->enemy;
	tmp = (t_enemy *) malloc(sizeof(t_enemy));
	if (tmp == NULL)
		error_msg(game, MALLOC_ERR);
	tmp->x = x;
	tmp->y = y;
	tmp->next = NULL;
	if (game->enemy == NULL)
	{
		game->enemy = tmp;
		return ;
	}
	while (tmp_game->next != NULL)
		tmp_game = tmp_game->next;
	tmp_game->next = tmp;
}

int	rand_num(int min, int max)
{
	return (min + rand() % (max - min + 1));
}

void	generate_enemies(t_game *game, int x, int y, int i)
{
	int		n;

	n = 0;
	while (i < N_ENEMIES)
	{
		x = rand_num(0, game->width -1);
		y = rand_num(0, game->height - 1);
		if (game->map[y][x] == '0')
		{
			game->map[y][x] = 'Y';
			if (enemy_path(game) == 1)
			{
				enemy_init(game, x, y);
				i++;
			}
			else
			{
				game->map[y][x] = '0';
				if (++n == counter_zeros(game->map))
					error_msg(game, ENEMIES_LOCATION_FAIL);
			}
		}
	}
}

void	enemies_animation(t_game *game)
{
	int		x;
	int		y;

	x = 0;
	y = 0;
	while (game->map[y] != NULL)
	{
		while (game->map[y][x])
		{
			if (game->map[y][x] == 'Y')
				mlx_put_image_to_window(game->mlx, game->win.win,
					game->img.enemy_tt, (80 + x * T_SIZE), (y * T_SIZE));
			x++;
		}
		y++;
		x = 0;
	}
}
