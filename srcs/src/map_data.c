#include "../../includes/cub3D.h"

// void	bit_shift_rgb(int r, int g, int b, t_core *c)
// {
// 	if (c->texture->bool_rgb == 1)
// 	{
// 		c->texture->rgb_c = 0;
// 		c->texture->rgb_c += r << 16;
// 		c->texture->rgb_c += g << 8;
// 		c->texture->rgb_c += b;
// 	}
// 	else
// 	{
// 		c->texture->rgb_f = 0;
// 		c->texture->rgb_f += r << 16;
// 		c->texture->rgb_f += g << 8;
// 		c->texture->rgb_f += b;
// 	}
// }

// void	convert_color(t_core *c)
// {
// 	int r;
// 	int g;
// 	int b;
// 	char **tab;

// 	r = 0;
// 	g = 0;
// 	b = 0;
// 	if (c == NULL || c->texture->C == NULL || c->texture->F == NULL)
// 	{
// 		printf("Erreur : les données sont NULL.\n");
// 		exit(1);
// 	}
// 	while (c->texture->bool_rgb < 2)
// 	{
// 		if (c->texture->bool_rgb == 1)
// 			tab = splitt(c->texture->C, ',');
// 		else
// 			tab = splitt(c->texture->F, ',');
// 		r = atoi(tab[0]);
// 		g = atoi(tab[1]);
// 		b = atoi(tab[2]);
// 		bit_shift_rgb(r, g, b, c);
// 		c->texture->bool_rgb++;
// 		free_tab(tab);
// 	}
// 	// if (tab)
// 	// 	free_tab(tab);
// }

// void	assign_texture(t_core *c, int i ,int j)
// {

// }

void	put_path(t_core *c, int what, int space)
{
	if (what == 1)
		c->texture->no = ft_substr(c->line, space + 3, str_len_modif(c->line) - space -3);
			if (!file_exists(c->texture->no))
				c->map->error = 1;
			else
				c->map->NO = 1;
	if (what == 2)
		c->texture->so = ft_substr(c->line, space + 3, str_len_modif(c->line) - space -3);
			if (!file_exists(c->texture->so))
				c->map->error = 1;
			else
				c->map->SO = 1;
	if (what == 3)
		c->texture->we = ft_substr(c->line, space + 3, str_len_modif(c->line) - space -3);
			if (!file_exists(c->texture->we))
				c->map->error = 1;
			else
				c->map->WE = 1;
	if (what == 4)
		c->texture->ea = ft_substr(c->line, space + 3, str_len_modif(c->line) - space -3);
			if (!file_exists(c->texture->ea))
				c->map->error = 1;
			else
				c->map->EA = 1;
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
	return (1);
}

int	is_valid_texture(char *line, t_core *c)
{
	if ((*line == 'N' && *(line + 1) == 'O'))
	{
		printf("NO\n");
		if (!test_it(c, 1))
			return (0);
	}
	else if ((*line == 'S' && *(line + 1) == 'O'))
	{
		printf("SO\n");
		if (!test_it(c, 2))
			return (0);
	}
	else if ((*line == 'W' && *(line + 1) == 'E'))
	{
		printf("WE\n");
		if (!test_it(c, 3))
			return (0);
	}
	else if ((*line == 'E' && *(line + 1) == 'A'))
	{
		printf("EA\n");
		if (!test_it(c, 4))
			return (0);
	}
	return (1);
}

void	take_map_data(t_core *c)
{
	if (c->first_data == 1)
	{
		printf(B_G" -> Checking Textures\n"RESET);
		while (!c->texture_ok && c->line && c->line[0] != '\n')
		{
			if(!is_valid_texture(c->line, c))
			{
				printf(B_R" Error : Wrong texture path \u274c \n"RESET);
				c->map->error = 1;
				return ;
			}
			c->line = get_next_line(c->map->fd);
			printf("d = [%s]\n", c->line);
			if (c->map->NO && c->map->SO && c->map->WE && c->map->EA)
				c->texture_ok = 1;
		}
	}
	else if (c->first_data == 2)
	{
		printf(B_G" -> Checking Colors\n"RESET);
	}
}
