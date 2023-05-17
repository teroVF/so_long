/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antero <antero@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 15:09:28 by antero            #+#    #+#             */
/*   Updated: 2023/05/17 04:56:35 by antero           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft/libft.h"
# include <fcntl.h>
# include "libft/libft.h"
# include "mlx.h"
# include "image.h"
# include "keys.h"
# include "error_msg.h"

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
}	t_img;

typedef struct s_game
{
	void		*mlx;
	t_window	win;
	t_elements	elem;
	t_img		img;
	t_player	py;
	char		**map;
	char		**map_valid;
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
void	error_msg(t_game *game, char *error_msg);

#endif
