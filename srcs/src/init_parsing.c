#include "../../includes/cub3D.h"

t_core	*init_texture(t_core *c)
{
	c->texture->no = NULL;
	c->texture->so = NULL;
	c->texture->we = NULL;
	c->texture->ea = NULL;
	c->texture->F = 0;
	c->texture->C = 0;
	c->texture->bool_rgb = 0;
	c->map->NO = 0;
	c->map->SO = 0;
	c->map->WE = 0;
	c->map->EA = 0;
	c->map->C = 0;
	c->map->F = 0;
	return c;
}

t_core	*init_core(t_core *c)
{
	c = malloc(sizeof(t_core));
	if (!c)
	{
		perror("Error allocating memory for core");
		exit(EXIT_FAILURE);
	}
	c->map = malloc(sizeof(t_map));
	if (!c->map)
	{
		perror("Error allocating memory for map");
		exit(EXIT_FAILURE);
	}
	c->map->map = NULL;
	c->map->data = NULL;
	c->map->map_path = NULL;
	c->map->fd = 0;
	c->map->i = 0;
	c->map->error = 0;
	c->texture = malloc(sizeof(t_texture));
	c->line = NULL;
	c->data_ok = 0;
	if (!c->texture)
	{
		perror("Error allocating memory for texture");
		exit(EXIT_FAILURE);
	}
	return (init_texture(c));
}
