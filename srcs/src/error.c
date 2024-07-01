/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppitzini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 16:18:03 by ppitzini          #+#    #+#             */
/*   Updated: 2024/07/01 16:21:04 by ppitzini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

void	textures_error_alloc(t_core *c)
{
	perror("Error allocating memory for texture");
	if (c->map)
		free(c->map);
	exit(EXIT_FAILURE);
}

void	error_rgb(t_core *c, char **tab)
{
	printf(B_R ERROR_RGB RESET);
	printf(BOLD END_LINE RESET);
	if (tab)
		free_tab(tab);
	free_parsing(c);
	exit(0);
}

void	error_data(t_core *c)
{
	printf(B_R ERROR_DATA RESET);
	printf(BOLD END_LINE RESET);
	free_parsing(c);
	exit(0);
}
