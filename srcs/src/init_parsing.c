#include "../../includes/cub3D.h"

t_map *init_map(t_map *map)
{
	map = malloc(sizeof(t_map));
	map->map = NULL;
	map->map_path = NULL;
	map->fd = 0;
	map->i = 0;
	return (map);
}
