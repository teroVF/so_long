/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvieira <anvieira@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 15:09:28 by antero            #+#    #+#             */
/*   Updated: 2023/05/07 01:48:00 by anvieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft/libft.h"
#include <fcntl.h>
#include "libft/libft.h"
#include "mlx.h"
#include "image.h"
#include "keys.h"



typedef struct s_game
{
	void	*mlx;
	t_window	*win;
	t_elements	*elem;
	char	**map;
	char	**map_valid;
}		t_game;

typedef struct s_elements
{
	int		py;
	int		item;
	int		exit;	
}	t_elements;

typedef struct s_window
{
	void	*win;
	int		win_x;
	int		win_y;
}	t_window;



char	validate_map(char **map);
char	**read_map(char *pwd);
void render(t_game *game);

#endif