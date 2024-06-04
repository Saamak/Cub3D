#include "../../includes/cub3D.h"

void	bit_shift_rgb(int r, int g, int b, t_core *c)
{
	if (c->texture->bool_rgb == 1)
	{
		c->texture->rgb_c = 0;
		c->texture->rgb_c += r << 16;
		c->texture->rgb_c += g << 8;
		c->texture->rgb_c += b;
		printf("RGB C: %d\n", c->texture->rgb_c);
	}
	else
	{
		c->texture->rgb_f = 0;
		c->texture->rgb_f += r << 16;
		c->texture->rgb_f += g << 8;
		c->texture->rgb_f += b;
		printf("RGB F: %d\n", c->texture->rgb_f);
	}
}

void	convert_color(t_core *c)
{
	int r;
	int g;
	int b;
	char **tab;

	r = 0;
	g = 0;
	b = 0;
	if (c == NULL || c->texture->C == NULL || c->texture->F == NULL)
	{
		printf("Erreur : les données sont NULL.\n");
		exit(1);
	}
	while (c->texture->bool_rgb < 2)
	{
		if (c->texture->bool_rgb == 1)
			tab = splitt(c->texture->C, ',');
		else
			tab = splitt(c->texture->F, ',');
		r = atoi(tab[0]);
		g = atoi(tab[1]);
		b = atoi(tab[2]);
		bit_shift_rgb(r, g, b, c);
		c->texture->bool_rgb++;
		free_tab(tab);
	}
	// if (tab)
	// 	free_tab(tab);
}

void	assign_texture(t_core *c, int i ,int j)
{
	if (c->map->map[i][j] == 'N' && c->map->map[i][j + 1] == 'O')
		c->texture->no = ft_substr(c->map->map[i], j + 3,
			ft_strlen(c->map->map[i]) - j - 2);
	if (c->map->map[i][j] == 'S' && c->map->map[i][j + 1] == 'O')
		c->texture->so = ft_substr(c->map->map[i], j + 3,
			ft_strlen(c->map->map[i]) - j - 2);
	if (c->map->map[i][j] == 'W' && c->map->map[i][j + 1] == 'E')
		c->texture->we = ft_substr(c->map->map[i], j + 3,
			ft_strlen(c->map->map[i]) - j - 2);
	if (c->map->map[i][j] == 'E' && c->map->map[i][j + 1] == 'A')
		c->texture->ea = ft_substr(c->map->map[i], j + 3,
			ft_strlen(c->map->map[i]) - j - 2);
	if (c->map->map[i][j] == 'F' && c->map->map[i][j + 1] == ' ')
		c->texture->F = ft_substr(c->map->map[i], j + 2,
			ft_strlen(c->map->map[i]) - j - 1);
	if (c->map->map[i][j] == 'C' && c->map->map[i][j + 1] == ' ')
		c->texture->C = ft_substr(c->map->map[i], j + 2,
			ft_strlen(c->map->map[i]) - j - 1);
}

void	take_map_data(t_core *c)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (c->map->map[i])
	{
		while(c->map->map[i][j])
		{
			assign_texture(c, i, j);
			j++;
		}
		j = 0;
		i++;
	}
	convert_color(c);
}
