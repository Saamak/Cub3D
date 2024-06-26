#include "../../includes/cub3D.h"

void	print_texture(t_core *c)
{
	printf(B_Y"\n\n----| Reading Data : \n\n"RESET);
	printf("   NO: %s\n", c->texture->no);
	printf("   SO: %s\n", c->texture->so);
	printf("   WE: %s\n", c->texture->we);
	printf("   EA: %s\n", c->texture->ea);
	printf("   RGB C: %d\n", c->texture->rgb_c);
	printf("   RGB F: %d\n", c->texture->rgb_f);
}

void	print_map(char **map)
{
	int	i;

	i = 0;
	printf(B_G"\n\n----|Map read [OK]\n\n"RESET);
	while (map[i])
	{
		printf("%s\n", map[i]);
		i++;
	}
	printf("\n\n");
}
