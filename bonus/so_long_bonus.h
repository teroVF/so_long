/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antero <antero@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 15:09:28 by antero            #+#    #+#             */
/*   Updated: 2023/05/15 16:15:46 by antero           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG__BONUS_H
# define SO_LONG_BONUS_H
# define N_ENEMIES 30

# include "../libft/libft.h"
# include <fcntl.h>
# include <math.h>
# include "mlx.h"
# include "image_bonus.h"
# include "keys_bonus.h"

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

typedef struct s_img
{
	void	*wall_t;
	void	*floor_t;
	void	*player_t;
	void	*items_t;
	void	*exit_t;
	void	*friend_t;
	void	*enemy_t;
	void	*enemy_tt;
	void	*enemy_tev;
}	t_img;

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
char	**read_map(char *pwd);
void	render(t_game *game);
int		config_game(t_game *game);
void	move_player_y(t_game *game, int i);
void	move_player_x(t_game *game, int i);
int		end_program(t_game *game);
void	player_position(t_game *game);
void	generate_enemies(t_game *game);
void 	enemies_animation(t_game *game);
int		rand_num(int min, int max);
void	enemy_turn(t_game *game);
int		enemy_path(t_game *game);

#endif
