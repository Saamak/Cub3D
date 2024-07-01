#include "../../includes/cub3D.h"

void	bit_shift_rgb(int r, int g, int b, t_core *c)
{
	if (c->what == 'C')
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

int is_digit(char *str)
{
	int i = 0;
	while(str[i] == ' ')
		i++;
	while (str[i] && str[i] != '\n' && str[i] != '\0')
	{
		if (!isdigit(str[i]) || str[i] == '-')
			return (0);
		i++;
	}
	return (1);
}

void convert_rgb_F(t_core *c)
{
	int r;
	int g;
	int b;
	char **tab;

	r = 0;
	g = 0;
	b = 0;
	if (c == NULL || c->texture->F == NULL)
		error_rgb(c, NULL);
	tab = splitt(c->texture->F, ',');
	if ((tab[0] != NULL) || (tab[1] != NULL) || (tab[2] != NULL))
	{
		if (!is_digit(tab[0]) || !is_digit(tab[1]) || !is_digit(tab[2]))
			error_rgb(c, tab);
		r = atoi(tab[0]);
		g = atoi(tab[1]);
		b = atoi(tab[2]);
	}
	else
		error_rgb(c, tab);
	if (r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255)
		error_rgb(c, tab);
	c->what = 'F';
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
		error_rgb(c, NULL);
	tab = splitt(c->texture->C, ',');
	if ((tab[0] != NULL) && (tab[1] != NULL) && (tab[2] != NULL))
	{
		if (!is_digit(tab[0]) || !is_digit(tab[1]) || !is_digit(tab[2]))
        	error_rgb(c, tab);
		r = atoi(tab[0]);
		g = atoi(tab[1]);
		b = atoi(tab[2]);
	}
	else
		error_rgb(c, tab);
	if (r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255)
		error_rgb(c, NULL);
	c->what = 'C';
	bit_shift_rgb(r, g, b, c);
	c->map->C = 1;
	free_tab(tab);
}
