/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antero <antero@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 15:09:28 by antero            #+#    #+#             */
/*   Updated: 2023/05/06 02:50:48 by antero           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft/libft.h"
#include <fcntl.h>
#include "libft/libft.h"


typedef struct s_game
{
	void	*mlx;
	void	*window;
	int		window_x;
	int		window_y;
	int		collectibles;
	int		player;
	int		exit;
	char	**map;
	char	**map_valid
}		t_game;

typedef struct s_img
{
	void	*img_ptr;
	char	*addr;
	int		h;
	int		w;
	int		bpp;
	int		endian;
	int		line_len;
}		t_img

char	validate_map(char **map);

#endif