#include "../../includes/cub3D.h"

void	process(t_core *c, char *line, char b)
{
	if (b == 'N')
	{
		c->texture->no = ft_substr(line, 3, ft_strlen(line) - 2);
		if(!file_exists(c->texture->no))
			ft_exit(c);
	}
	if (b == 'S')
	{
		c->texture->so = ft_substr(line, 3, ft_strlen(line) - 2);
		if (!file_exists(c->texture->so))
			ft_exit(c);
	}
	if (b == 'W')
	{
		c->texture->we = ft_substr(line, 3, ft_strlen(line) - 2);
		if (!file_exists(c->texture->we))
			ft_exit(c);
	}
	if (b == 'E')
	{
		c->texture->ea = ft_substr(line, 3, ft_strlen(line) - 2);
		if (!file_exists(c->texture->ea))
			ft_exit(c);
	}
}


void view_line(char *line, t_core *c)
{
	if (line[0] == 'N' && line[0 + 1] == 'O' && line[0 + 2] == ' ')
		process(c, line, 'N');
	else if (line[0] == 'S' && line[0 + 1] == 'O' && line[0 + 2] == ' ')
		process(c, line, 'S');
	else if (line[0] == 'W' && line[0 + 1] == 'E' && line[0 + 2] == ' ')
		process(c, line, 'W');
	else if (line[0] == 'E' && line[0 + 1] == 'A' && line[0 + 2] == ' ')
		process(c, line, 'E');
	// if (line[i] == 'F' && line[i + 1] == ' ')
	// 	process(c, line, i);
	// if (line[i] == 'C' && line[i + 1] == ' ')
	// 	process(c, line, i);
	else
	{
		printf("Error : wrong map data\n");
		ft_exit(c);
	}
}

void	get_map_path(char *path, t_map *game)
{
	game->map_path = path;
	game->fd = open(game->map_path, O_RDONLY);
}

void	read_map(t_core *c)
{
	char	*line;
	char	*map;
	int		nb_line;

	nb_line = 0;
	map = malloc(sizeof(char) * 1);
	map[0] = '\0';
	while (1)
	{
		line = get_next_line(c->map->fd);
		if (line == NULL)
			break ;
		view_line(line, c);
		nb_line ++;
		map = ft_strjoin(map, line);
		free(line);
	}
	c->map->map = ft_split(map, '\n', c->map);
	// print_map(c->map->map);
	free(map);
	free(line);
	close(c->map->fd);
}
