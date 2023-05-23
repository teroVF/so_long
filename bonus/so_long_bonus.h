/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvieira <anvieira@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 02:58:17 by anvieira          #+#    #+#             */
/*   Updated: 2023/05/23 16:02:09 by anvieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H
# define N_ENEMIES 40

# include "../libft/libft.h"
# include <fcntl.h>
# include <math.h>
# include "../mlx/mlx.h"
# include "image_bonus.h"
# include "keys_bonus.h"
# include "error_msg.h"

typedef struct s_siz {
	int		y;
	int		x;
}	t_siz;

typedef struct s_elements
{
	int		py;
	int		item;
	int		exit;
}	t_elements;

typedef struct s_player
{
	int		x;
	int		y;
}	t_player;

typedef struct s_enemy
{
	int				x;
	int				y;
	struct s_enemy	*next;
}	t_enemy;

typedef struct s_window
{
	void	*win;
	int		win_x;
	int		win_y;
}	t_window;

typedef struct s_game
{
	void		*mlx;
	t_window	win;
	t_elements	elem;
	t_img		img;
	t_player	py;
	t_enemy		*enemy;
	char		**map;
	char		**map_valid;
	int			width;
	int			height;
	int			move_n;
}		t_game;

int		validate_map(t_game *game);
char	**read_map(char *pwd, t_game *game);
void	render(t_game *game);
int		config_game(t_game *game);
void	move_player_y(t_game *game, int i);
void	move_player_x(t_game *game, int i);
int		end_program(t_game *game);
int		end_program_fail(t_game *game);
void	player_position(t_game *game);
void	generate_enemies(t_game *game, int x, int y, int i);
void	enemies_animation(t_game *game);
int		rand_num(int min, int max);
void	enemy_turn(t_game *game);
int		enemy_path(t_game *game);
void	error_msg(t_game *game, char *error_msg);
void	counter_init(t_game *game);
void	counter_plus_one(t_game *game);
int		if_valid_path(t_game *game);
void	img_init(t_game *game);
void	img_init_bonus(t_game *game);
int		counter_zeros(char **map);

#endif
