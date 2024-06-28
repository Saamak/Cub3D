#include "../../includes/cub3D.h"

int main (int argc, char **argv)
{
	t_core *c;

	c = NULL;
	c = init_core(c);

	//--PARSING--//
	printf(BOLD"\n-------------------------------------------------\n\n\n"RESET);
	printf(B_Y"----| Cub3D input verifications...\n\n"RESET);
	first_checks_hub(argc, argv, c);
	if (c->map->error)
		free_parsing(c);
	if(!read_hub(c) || c->map->error)
		free_parsing(c);
	print_texture(c);
	printf(BOLD"\n\n-----------------------------------------------\n"RESET);
	return 0;
}
