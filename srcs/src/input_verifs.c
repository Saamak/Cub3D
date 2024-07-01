/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_verifs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppitzini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 16:22:08 by ppitzini          #+#    #+#             */
/*   Updated: 2024/07/01 19:33:58 by ppitzini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

int	ac_checks(int ac)
{
	if (ac != 2)
	{
		printf(B_R ERROR_ARGUMENTS RESET);
		printf(BOLD END_LINE RESET);
		return (1);
	}
	printf(B_G"   |Enought Arguments \xE2\x9C\x93 \n\n"RESET);
	return (0);
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
			printf(B_R ERROR_EXTENSION RESET);
			printf(BOLD END_LINE RESET);
			return (1);
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
	if (!file_exists(av[1]))
	{
		c->map->error = 1;
		return (1);
	}
	c->map->map_path = av[1];
	return (0);
}
