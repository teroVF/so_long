/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvieira <anvieira@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 01:27:45 by antero            #+#    #+#             */
/*   Updated: 2023/05/20 17:44:27 by anvieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

char	**read_map(char *pwd, t_game *game)
{
	char	**map;
	char	*all_line;
	char	*line;
	int		i;

	i = open(pwd, O_RDONLY);
	if (i == -1)
		error_msg(game, OPEN_MAP_FILE_ERR);
	all_line = ft_strdup("");
	while (1)
	{
		line = get_next_line(i);
		if (line == NULL)
			break ;
		all_line = ft_strjoin(all_line, line);
		free(line);
		line = NULL;
	}
	map = ft_split(all_line, '\n');
	free(all_line);
	if (close(i) == -1)
		error_msg(game, CLOSE_MAP_FILE_ERR);
	return (map);
}
