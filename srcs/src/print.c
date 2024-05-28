#include "../../includes/cub3D.h"

void	print_map(char **map)
{
	int	i;

	i = 0;
	printf(B_Y"\n\n----|Map read [OK]\n\n"RESET);
	while (map[i])
	{
		printf("%s\n", map[i]);
		i++;
	}
	printf("\n\n");
}
