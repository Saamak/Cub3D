#include "../../includes/cub3D.h"

void	ft_exit(t_core *c)
{
	if (c->texture->no)
		free(c->texture->no);
	if (c->texture->so)
		free(c->texture->so);
	if (c->texture->we)
		free(c->texture->we);
	if (c->texture->ea)
		free(c->texture->ea);
	if (c->texture->C)
		free(c->texture->C);
	if (c->texture->F)
		free(c->texture->F);
	if (c->texture)
		free(c->texture);
	if (c->map)
	{
		free_map(c->map);
		free(c->map);
	}
	if (c)
		free(c);
	exit(1);
}


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
	if (map->map == NULL)
		return ;
	while (map->map[i])
	{
		free(map->map[i]);
		i++;
	}
	free(map->map);
}

void	free_parsing(t_core *c)
{
	if (c)
	{
		if (c->line)
			free(c->line);
		if (c->map)
		{
			if (c->map->map)
				free(c->map->map);
			if (c->map->data)
				free(c->map->data);
			free(c->map);
		}
		if (c->texture)
		{
			if (c->texture->no)
				free(c->texture->no);
			if (c->texture->so)
				free(c->texture->so);
			if (c->texture->we)
				free(c->texture->we);
			if (c->texture->ea)
				free(c->texture->ea);
			if (c->texture->F)
				free(c->texture->F);
			if (c->texture->C)
				free(c->texture->C);
			free(c->texture);
		}
		free(c);
	}
	exit(1);
}
