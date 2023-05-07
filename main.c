/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvieira <anvieira@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 00:57:15 by anvieira          #+#    #+#             */
/*   Updated: 2023/05/07 01:41:37 by anvieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// void	fill_with_elements()
// {
	
// }

// initialization (t_game *game)
// {
// 	void *img_ptr;
// 	game->mlx = mlx_init();
// 	if (!game->mlx)
// 		return (1);
// 	game->window = mlx_new_window (game->mlx, game->window_x, game->window_y, "So_long");
// 	if (!game->window)
// 		return (2);
		
	
// 	mlx_loop(!game->mlx);

// }

t_game *struck_init()
{
		
}

int main(int argc, char *argv[])
{
	t_game *game;
	char	*pwd;

	if (argc < 2)
		return (1);
	pwd = ft_strdup("./maps/");
	pwd = ft_strjoin(pwd, argv[1]);
	game = struck_init();
	game->map = read_map(pwd);
	printf("%s\n", game->map[0]);
	if(validate_map(game->map) == 0)
	{
	printf("entrou1");
		return (EXIT_FAILURE);
	}
	render(game);
	
	// initialization(game);
	// render_game(game);
	return 0;
}
