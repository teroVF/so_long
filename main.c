/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antero <antero@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 00:57:15 by anvieira          #+#    #+#             */
/*   Updated: 2023/05/06 02:23:48 by antero           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	fill_with_elements()
{
	
}

int main(int argc, char *argv[])
{
	t_game *game;
	char	*pwd;
	char	**map;
	int		n;

	if (argc < 2)
		return (1);
	game = malloc (sizeof(t_game) * 1);
	pwd = ft_strdup("./maps/");
	pwd = ft_strjoin(pwd, argv[1]);
	game->map = read_map(pwd);
	if(validate_map(game->map) == 0)
		return (EXIT_FAILURE);
	initiatilization(game);
	render_game(game);
	//ate aqui o mapa esta montado graficamente.
	
	return 0;
}
