#include "../../includes/cub3D.h"

// void	is_colors(char *line, t_core *c)
// {
// 	while (*line == ' ')
// 		line++;
// 	if (*line == '\n')
// 		return ;
// 	if (*line == 'F' || *line == 'C')
// 		c->first_data = 2;
// }

// void	is_textures(char *line, t_core *c)
// {
// 	while (*line == ' ')
// 		line++;
// 	if (*line == '\n')
// 		return ;
// 	if ((*line == 'N' && *(line + 1) == 'O')
// 		|| (*line == 'S' && *(line + 1) == 'O')
// 		|| (*line == 'W' && *(line + 1) == 'E')
// 		|| (*line == 'E' && *(line + 1) == 'A'))
// 		if (line[2] == ' ')
// 			c->first_data = 1;
// }

void	skip_lines(int fd, t_core *c) // Quelle data en premier ?
{
	c->line = get_next_line(fd);
	while(c->line && c->line[0] == '\n')
	{
		free(c->line);
		c->line = get_next_line(fd);
		if (!c->line)
		{
			c->map->error = 1;
			printf(B_R" Error : empty map \u274c \n"RESET);
			return ;
		}
	}
}

int	read_hub(t_core *c)
{
	c->map->fd = open(c->map->map_path, O_RDONLY);
	if (c->map->fd == -1)
	{
		printf(B_R"   | Error : Can't open file \u274c \n"RESET);
		c->map->error = 1;
		return (0);
	}
	skip_lines(c->map->fd, c);
	take_map_data(c);
	if (!c->map->error)
		printf(B_G"   \n               Data are correct \xE2\x9C\x93 \n"RESET);
	return (1);
}
