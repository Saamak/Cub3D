#include "../../includes/cub3D.h"

int main (int argc, char **argv)
{
	t_core *c;

	c = NULL;
	c = init_core(c);

	//--PARSING--//
	printf("------------------------------------\n\n\n");
	printf(B_Y"Cub3D input verifications...\n\n"RESET);
	first_checks_hub(argc, argv, c);
	if (c->map->error)
		free_parsing(c);
	read_map(c);
	// take_map_data(c);
	// textures_verification(c);
	// print_texture(c);
	free_parsing(c);
	printf("\n\n\n------------------------------------\n");
	return 0;
}
