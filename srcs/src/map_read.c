#include "../../includes/cub3D.h"

void	get_map_path(char *path, t_map *game)
{
	game->map_path = path;
	game->fd = open(game->map_path, O_RDONLY);
	printf(B_G"\n----|Map path : %s [OK]\n"RESET, game->map_path);
}

void	read_map(t_map *map)
{
	char	*line;
	char	*all_lines;
	int		nb_line;

	nb_line = 0;
	all_lines = malloc(sizeof(char) * 1);
	all_lines[0] = '\0';
	while (1)
	{
		line = get_next_line(map->fd);
		if (line == NULL)
			break ;
		nb_line ++;
		all_lines = ft_strjoin(all_lines, line);
		free(line);
	}
	map->map = ft_split(all_lines, '\n', map);
	print_map(map);
	free(all_lines);
	free(line);
	close(map->fd);
}
