#include "../../includes/cub3D.h"

int	ac_checks(int ac)
{
	if (ac != 2)
	{
		printf(B_R" Error : Program need 1 argument\n"RESET);
		return (1);
	}
	return(0);
}

int	extension(char *str, char *ext)
{
	int	i;
	int	j;

	i = ft_strlen(str) - 1;
	j = ft_strlen(ext) - 1;
	while (i >= 0 && j >= 0)
	{
		if (str[i] != ext[j])
		{
			printf(B_R" Error : wrong file extension\n"RESET);
			return 1;
		}
		i--;
		j--;
	}
	return (0);
}

int	first_checks_hub(int ac, char **av, t_core *c)
{
	if (ac_checks(ac))
	{
		c->map->error = 1;
		return (1);
	}
	if (extension(av[1], ".cub"))
	{
		c->map->error = 1;
		return (1);
	}
	if(!file_exists(av[1]))
	{
		c->map->error = 1;
		return (1);
	}
	get_map_path(av[1], c->map);
	return (0);
}
