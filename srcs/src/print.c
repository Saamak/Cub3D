#include "../../includes/cub3D.h"

void	print_map(t_map *map)
{
	printf(B_Y"\n\nMap :\n\n"RESET);
	int i;

	i = 0;
	while (map->map[i])
	{
		printf("%s\n", map->map[i]);
		i++;
	}
}
