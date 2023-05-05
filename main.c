/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvieira <anvieira@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 00:57:15 by anvieira          #+#    #+#             */
/*   Updated: 2023/05/05 00:59:56 by anvieira         ###   ########.fr       */
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
	all_line = ft_strdup("");
	while (1)
	{
		line = get_next_line(i);
		if(line == NULL)
			break;
		all_line = ft_strjoin(all_line, line);
		free(line);
		line = NULL;
	}
	map = ft_split(all_line, '\n');
	free(all_line);
	return (map);
}

int main(int argc, char *argv[])
{
	char	*pwd;
	char	**map;
	int		n;

	if (argc < 2)
		return (1);
	pwd = ft_strdup("./maps/");
	pwd = ft_strjoin(pwd, argv[1]);
	printf("%s\n", pwd);

	map = read_map(pwd);
	n = validate_map(map);
	printf("%d", n);
	// validate_map();
	// window = mlx_new_window();
	return 0;
}
