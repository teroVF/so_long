/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvieira <anvieira@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 19:14:23 by anvieira          #+#    #+#             */
/*   Updated: 2023/05/07 01:29:17 by anvieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void render(t_game *game)
{
    int		n = 0;
    int		i = 0;
	int		l = 70;
	int		h = 0;
	int		size = 0;
    void	*imgF;
    void	*imgT;
    void	*imgP;
    void	*imgCol;
    void	*imgExit;
    printf("aqui");
    game->mlx = mlx_init();
	game->window = mlx_new_window(game->mlx, 770, 420, "SO_LONG");
	imgF = mlx_xpm_file_to_image(game->mlx, FLOOR_TILE, &l, &l);
	imgT = mlx_xpm_file_to_image(game->mlx, TREE_TILE, &l, &l);
	imgP = mlx_xpm_file_to_image(game->mlx, PLAYER, &l, &l);
	imgCol = mlx_xpm_file_to_image(game->mlx, COLLECTIBLES, &l, &l);
	imgExit = mlx_xpm_file_to_image(game->mlx, EXIT , &l, &l);
	while (i < 6)
	{
        while (game->map[i][n])
        {
            if (game->map[i][n] == '1')
                mlx_put_image_to_window(game->mlx, game->window, imgT, size, h);
            if (game->map[i][n] == '0')
                mlx_put_image_to_window(game->mlx, game->window, imgF, size, h);
            if (game->map[i][n] == 'P')
            {
                mlx_put_image_to_window(game->mlx, game->window, imgF, size, h);
                mlx_put_image_to_window(game->mlx, game->window, imgP, size, h);
            }
            if (game->map[i][n] == 'C')
                mlx_put_image_to_window(game->mlx, game->window, imgCol, size, h);
            if (game->map[i][n] == 'E')
                mlx_put_image_to_window(game->mlx, game->window, imgExit, size, h);
		    size += 70;
		    n++;
        }
        h += 70;
        n = 0;
        size = 0;
        i++;
	}	
	mlx_loop(game->mlx);
}
