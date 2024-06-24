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

void	take_map_data(t_core *c)
{
	if (c->first_data == 1)
	{
		printf(B_G" -> Checking Textures\n"RESET);
	}
	else if (c->first_data == 2)
	{
		printf(B_G" -> Checking Colors\n"RESET);
	}
}
