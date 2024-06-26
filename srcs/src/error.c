/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppitzini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 16:18:03 by ppitzini          #+#    #+#             */
/*   Updated: 2024/07/01 20:07:06 by ppitzini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"


void error_map(t_core *c)
{
	printf(B_R ERROR_INVALID_MAP RESET);
	printf(BOLD END_LINE RESET);
	free_parsing(c);
	exit(0);
}

void	textures_error_alloc(t_core *c)
{
	printf (B_R"   |Error : Double textures \u274c \n" RESET);
	free_parsing(c);
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
