#include "../../includes/cub3D.h"

void	error_rgb(t_core *c, char **tab)
{
	printf(B_R"\n   | Erreur : les valeurs RGB ne sont pas correctes. \u274c \n"RESET);
	printf(BOLD"\n\n-----------------------------------------------\n"RESET);
	if (tab)
		free_tab(tab);
	free_parsing(c);
	exit(0);
}

void	error_data(t_core *c)
{
	printf(B_R"\n   | Erreur : Invalid data \u274c \n"RESET);
	printf(BOLD"\n\n-----------------------------------------------\n"RESET);
	free_parsing(c);
	exit(0);
}
