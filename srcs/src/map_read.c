#include "../../includes/cub3D.h"

void	is_colors(char *line, t_core *c)
{
	while (*line == ' ')
		line++;
	if (*line == '\n')
		return ;
	if (*line == 'F' || *line == 'C')
		c->first_data = 2;
}

void	is_textures(char *line, t_core *c)
{
	while (*line == ' ')
		line++;
	if (*line == '\n')
		return ;
	if ((*line == 'N' && *(line + 1) == 'O')
		|| (*line == 'S' && *(line + 1) == 'O')
		|| (*line == 'W' && *(line + 1) == 'E')
		|| (*line == 'E' && *(line + 1) == 'A'))
		if (line[2] == ' ')
			c->first_data = 1;
}

void	is_first(int fd, t_core *c) // Quelle data en premier ?
{
	char *line;
	line = get_next_line(fd);
	printf("d = [%s]\n", line);
	while(line && line[0] == '\n')
	{
		free(line);
		line = get_next_line(fd);
		if (!line)
		{
			c->map->error = 1;
			printf(B_R" Error : empty map \u274c \n"RESET);
			return ;
		}
		printf("d = [%s]\n", line);
	}
	is_textures(line, c);
	is_colors(line, c);
	if (c->first_data == 0)
	{
		c->map->error = 1;
		printf(B_R" Error : Wrong map data \u274c \n"RESET);
	}
}

void	read_hub(t_core *c)
{
	c->map->fd = open(c->map->map_path, O_RDONLY);
	if (c->map->fd == -1)
	{
		printf(B_R" Error : Can't open file \u274c \n"RESET);
		c->map->error = 1;
		exit(0) ;
	}
	is_first(c->map->fd, c);
	take_map_data(c);
}
