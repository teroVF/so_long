/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antero <antero@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 01:27:45 by antero            #+#    #+#             */
/*   Updated: 2023/05/12 00:59:20 by antero           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**read_map(char *pwd)
{
	char	**map;
	char	*all_line;
	char	*line;
	int		i;

	i = open(pwd, O_RDONLY);
	if (i == -1)
		return (NULL);
	all_line = ft_strdup("");
	while (1)
	{
		line = get_next_line(i);
		if (line == NULL)
		{
			free(line);
			break ;
		}
		all_line = ft_strjoin(all_line, line);
		free(line);
		line = NULL;
	}
	map = ft_split(all_line, '\n');
	free(all_line);
	return (map);
}
