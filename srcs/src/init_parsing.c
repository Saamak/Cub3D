#include "../../includes/cub3D.h"

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
	c->map->map_path = NULL;
	c->map->fd = 0;
	c->map->i = 0;
	c->map->error = 0;
	c->texture = malloc(sizeof(t_texture));
	if (!c->texture)
	{
		perror("Error allocating memory for texture");
		exit(EXIT_FAILURE);
	}
	c->texture->no = NULL;
	c->texture->so = NULL;
	c->texture->we = NULL;
	c->texture->ea = NULL;
	return c;
}
