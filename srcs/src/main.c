#include "../../includes/cub3D.h"

int main (int argc, char **argv)
{
	t_core *c;

	c = NULL;
	c = init_core(c);

	//--PARSING--//
	printf("------------------------------------\n\n\n");
	printf(B_Y"Cub3D input verifications...\n"RESET);
	first_checks_hub(argc, argv, c);
	if (c->map->error)
	{
		free(c->map->map);
		free(c->map);
		free(c->texture);
		free(c);
		return (1);
	}
	read_map(c);
	free_map(c->map);
	free(c->map);
	free(c->texture);
	free(c);
	printf("\n\n\n------------------------------------\n");

	return 0;
}
