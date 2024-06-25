#include "../../includes/cub3D.h"

void	bit_shift_rgb(int r, int g, int b, t_core *c)
{
	if (c->texture->bool_rgb == 1)
	{
		c->texture->rgb_c = 0;
		c->texture->rgb_c += r << 16;
		c->texture->rgb_c += g << 8;
		c->texture->rgb_c += b;
	}
	else
	{
		c->texture->rgb_f = 0;
		c->texture->rgb_f += r << 16;
		c->texture->rgb_f += g << 8;
		c->texture->rgb_f += b;
	}
}

void	convert_rgb_F(t_core *c)
{
	int r;
	int g;
	int b;
	char **tab;

	r = 0;
	g = 0;
	b = 0;
	if (c == NULL || c->texture->F == NULL)
	{
		printf("Erreur : les données sont NULL.\n");
		exit(1);
	}
	tab = splitt(c->texture->F, ',');
	r = atoi(tab[0]);
	g = atoi(tab[1]);
	b = atoi(tab[2]);
	if (r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255)
	{
		printf(B_R"Erreur : les valeurs RGB ne sont pas correctes. \u274c \n"RESET);
		exit(1);
	}
	bit_shift_rgb(r, g, b, c);
	c->map->F = 1;
	free_tab(tab);
}

void	convert_rgb_C(t_core *c)
{
	int r;
	int g;
	int b;
	char **tab;

	r = 0;
	g = 0;
	b = 0;
	if (c == NULL || c->texture->C == NULL)
	{
		printf("Erreur : les données sont NULL.\n");
		c->map->error = 1;
	}
	tab = splitt(c->texture->C, ',');
	r = atoi(tab[0]);
	g = atoi(tab[1]);
	b = atoi(tab[2]);
	if (r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255)
	{
		printf(B_R" Erreur : les valeurs RGB ne sont pas correctes. \u274c \n"RESET);
		c->map->error = 1;
	}
	bit_shift_rgb(r, g, b, c);
	c->map->C = 1;
	free_tab(tab);
}

void	check_color(t_core *c, char *line, char what)
{
	int i;
	int r;
	int g;
	int b;

	i = 1;
	r = 0;
	g = 0;
	b = 0;
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
	else
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
	{
		check_color(c, line, 'F');
	}
	else if (*line == 'C')
	{
		check_color(c, line, 'C');
	}
	else
		return (0);
	return (1);
}

void	take_map_data(t_core *c)
{
	printf(B_G" -> Checking Data\n"RESET);
	while (!c->data_ok && c->line && !c->map->error)
	{
		while(c->line && c->line[0] == '\n')
		{
			free(c->line);
			c->line = get_next_line(c->map->fd);
		}
		if(!is_valid_data(c->line, c))
		{
			printf(B_R" Error : Wrong texture path \u274c \n"RESET);
			c->map->error = 1;
			return ;
		}
		c->line = get_next_line(c->map->fd);
		if (c->map->NO && c->map->SO && c->map->WE && c->map->EA && c->map->C && c->map->F)
			c->data_ok = 1;
	}
}
