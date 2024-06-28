#include "../../includes/cub3D.h"

void	put_path_extend(t_core *c, int what, int space)
{
	if (what == 3)
	{
		c->texture->we = ft_substr(c->line, space + 3, str_len_modif(c->line) - space -3);
		if (!file_exists(c->texture->we))
			c->map->error = 1;
		else
			c->map->WE = 1;
	}
	if (what == 4)
	{
		c->texture->ea = ft_substr(c->line, space + 3, str_len_modif(c->line) - space -3);
		if (!file_exists(c->texture->ea))
			c->map->error = 1;
		else
			c->map->EA = 1;
	}
}

void	check_color(t_core *c, char *line, char what)
{
	int i;

	i = 1;
	while (line[i] == ' ')
		i++;
	if (line[i] == '\n')
	{
		c->map->error = 1;
		return ;
	}
	if (what == 'F')
	{
		c->texture->F = ft_substr(line, i, str_len_modif(line) - i);
		convert_rgb_F(c);
	}
	else if (what == 'C')
	{
		c->texture->C = ft_substr(line, i, str_len_modif(line) - i);
		convert_rgb_C(c);
	}
}

void	put_path(t_core *c, int what, int space)
{
	if (what == 1)
	{
		c->texture->no = ft_substr(c->line, space + 3, str_len_modif(c->line) - space -3);
		if (!file_exists(c->texture->no))
			c->map->error = 1;
		else
			c->map->NO = 1;
	}
	if (what == 2)
	{
		c->texture->so = ft_substr(c->line, space + 3, str_len_modif(c->line) - space -3);
		if (!file_exists(c->texture->so))
			c->map->error = 1;
		else
			c->map->SO = 1;
	}
	if (what == 3 || what == 4)
		put_path_extend(c, what, space);

}

int	test_it(t_core *c, int what)
{
	int space;
	int i;

	i = 3;
	space = 0;
	while (c->line[i] == ' ')
	{
		space++;
		i++;
	}
	if (c->line[i] == '\n')
	{
		c->map->error = 1;
		return (0);
	}
	put_path(c, what, space);
	if (c->map->error)
		return (0);
	return (1);
}

int	is_valid_data (char *line, t_core *c)
{
	if ((*line == 'N' && *(line + 1) == 'O'))
	{
		if (!test_it(c, 1))
			return (0);
	}
	else if ((*line == 'S' && *(line + 1) == 'O'))
	{
		if (!test_it(c, 2))
			return (0);
	}
	else if ((*line == 'W' && *(line + 1) == 'E'))
	{
		if (!test_it(c, 3))
			return (0);
	}
	else if ((*line == 'E' && *(line + 1) == 'A'))
	{
		if (!test_it(c, 4))
			return (0);
	}
	else if (*line == 'F')
		check_color(c, line, 'F');
	else if (*line == 'C')
		check_color(c, line, 'C');
	else
		error_data(c);
	return (1);
}

void	take_map_data(t_core *c)
{
	printf(B_Y"\n----| Checking Data\n\n"RESET);
	while (!c->data_ok && !its_map(c->line) && c->line && !c->map->error)
	{
		while(c->line && c->line[0] == '\n')
		{
			free(c->line);
			c->line = get_next_line(c->map->fd);
		}
		if (its_map(c->line))
			break ;
		if(!is_valid_data(c->line, c))
		{
			c->map->error = 1;
			return ;
		}
		free(c->line);
		c->line = get_next_line(c->map->fd);
		if (c->map->NO && c->map->SO && c->map->WE && c->map->EA && c->map->C && c->map->F)
			c->data_ok = 1;
	}
	if (!c->data_ok)
		error_data(c);
}
