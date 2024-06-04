#include "../../includes/cub3D.h"

void	free_tab(char **tab)
{
	int i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

void	free_map(t_map *map)
{
	int i;

	i = 0;
	while (map->map[i])
	{
		free(map->map[i]);
		i++;
	}
	free(map->map);
}

void	free_parsing(t_core *c)
{
	if (c->map->error)
	{
		free(c->map->map);
		free(c->map);
		free(c->texture);
		free(c);
		exit(1);
	}
	if (c->map)
	{
		free_map(c->map);
		free(c->map);
		free(c->texture);
		free(c);
	}
}
