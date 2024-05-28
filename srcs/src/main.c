#include "../../includes/cub3D.h"

int main (int ac , char **av)
{
	t_map *map;

	map = NULL;
	map = init_map(map);
	//--USER_INPUT--//
	printf("------------------------------------\n\n\n");
	printf(B_Y"Cub3D input verifications...\n"RESET);
	if(first_checks_hub(ac, av, map))
	{
		free(map);
		return (1);
	}






	free_map(map);
	free(map);
	printf("\n\n\n------------------------------------\n");
}
