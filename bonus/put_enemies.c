/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_enemies.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antero <antero@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 02:59:08 by antero            #+#    #+#             */
/*   Updated: 2023/05/15 17:47:40 by antero           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	enemy_init(t_game *game, int x, int y)
{
	t_enemy		*tmp;
	t_enemy		*tmp_game;

	tmp_game = game->enemy;
	tmp = (t_enemy *) malloc(sizeof(t_enemy));
	if(tmp == NULL)
		return ;
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

int rand_num(int min, int max)
{
	return min + rand() % (max - min + 1);
}

void	generate_enemies(t_game *game)
{
	int		x;
	int		y;
	int		i;

	x = 0;
	y = 0;
	i = 0;
	while (i < N_ENEMIES)
	{
		x = rand_num(0, game->width -1);
		y = rand_num(0, game->height - 1);
		if(game->map[y][x] == '0')
		{
			game->map[y][x] = 'Y';
			if (enemy_path(game) == 1)
			{
				enemy_init(game, x, y);
				i++;
			}
			else
				game->map[y][x] = '0';
		}

	}
}


int enemies_animation_1(t_game *game)
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
					game->img.enemy_tt, (x * T_SIZE), (y * T_SIZE));
			x++;
		}
		y++;
		x = 0;
	}
	return (1);
}

void enemies_animation_2(t_game *game)
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
					game->img.enemy_tev, (x * T_SIZE), (y * T_SIZE));
			x++;
		}
		y++;
		x = 0;
	}
}


void enemies_animation(t_game *game)
{
    enemies_animation_1(game);
    sleep(3); // Pausa de 3 segundos
    enemies_animation_2(game);
}
