/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_data_color.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppitzini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 16:32:57 by ppitzini          #+#    #+#             */
/*   Updated: 2024/07/01 18:34:43 by ppitzini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

void	color_process(char *line, t_core *c)
{
	while (*line == ' ')
		line++;
	if (*line == 'F')
	{
		if (c->texture->F)
			error_data(c);
		else
			check_color(c, line, 'F');
	}
	else if (*line == 'C')
	{
		if (c->texture->C)
			error_data(c);
		else
			check_color(c, line, 'C');
	}
	else
		error_data(c);
}

void	check_color(t_core *c, char *line, char what)
{
	int	i;

	i = 1;
	line += 1;
	while (line[i] == ' ')
		i++;
	if (line[i] == '\n')
	{
		c->map->error = 1;
		return ;
	}
	if (what == 'F')
	{
		c->texture->F = ft_strdup_end(line + i);
		printf("F = %s\n", c->texture->F);
		convert_rgb_F(c);
	}
	else if (what == 'C')
	{
		c->texture->C = ft_strdup_end(line + i);
		printf("C = %s\n", c->texture->C);
		convert_rgb_C(c);
	}
}
