#include "../../includes/cub3D.h"

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
