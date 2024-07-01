/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_data_texture.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppitzini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 16:27:35 by ppitzini          #+#    #+#             */
/*   Updated: 2024/07/01 19:04:42 by ppitzini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

void	put_path_extend(t_core *c, int what, char *line)
{
	if (what == 3)
	{
		c->texture->we = ft_strdup_end(line);
		if (!file_exists(c->texture->we))
			c->map->error = 1;
		else
			c->map->WE = 1;
	}
	if (what == 4)
	{
		c->texture->ea = ft_strdup_end(line);
		if (!file_exists(c->texture->ea))
			c->map->error = 1;
		else
			c->map->EA = 1;
	}
}

void	put_path(t_core *c, int what, char *line)
{
	if (what == 1)
	{
		c->texture->no = ft_strdup_end(line);
		if (!file_exists(c->texture->no))
			c->map->error = 1;
		else
			c->map->NO = 1;
	}
	if (what == 2)
	{
		c->texture->so = ft_strdup_end(line);
		if (!file_exists(c->texture->so))
			c->map->error = 1;
		else
			c->map->SO = 1;
	}
	if (what == 3 || what == 4)
		put_path_extend(c, what, line);
}

int	test_it(char *line, t_core *c, int what)
{
	line +=2;
	while (*line == ' ')
		line++;
	if (*line == '\n')
	{
		c->map->error = 1;
		return (0);
	}
	put_path(c, what, line);
	if (c->map->error)
		return (0);
	return (1);
}

int	is_valid_data(char *line, t_core *c)
{
	while (*line == ' ')
		line++;
	if ((*line == 'N' && *(line + 1) == 'O') || (*line == 'N' && *(line + 1) == ' '))
	{
		if (c->map->NO)
			textures_error_alloc(c);
		else
			return (test_it(line, c, 1));
	}
	else if ((*line == 'S' && *(line + 1) == 'O') || (*line == 'S' && *(line + 1) == ' '))
	{
		if (c->map->SO)
			textures_error_alloc(c);
		else
			return (test_it(line, c, 2));
	}
	else if ((*line == 'W' && *(line + 1) == 'E') || (*line == 'W' && *(line + 1) == ' '))
	{
		if (c->map->WE)
			textures_error_alloc(c);
		else
			return (test_it(line, c, 3));
	}
	else if ((*line == 'E' && *(line + 1) == 'A') || (*line == 'E' && *(line + 1) == ' '))
	{
		if (c->map->EA)
			textures_error_alloc(c);
		else
			return (test_it(line, c, 4));
	}
	else
		color_process(line, c);
	return (1);
}

void	take_map_data(t_core *c)
{
	printf(B_Y"\n----| Checking Data\n\n"RESET);
	while (!c->data_ok && c->line && !c->map->error)
	{
		while (c->line && c->line[0] == '\n')
		{
			free(c->line);
			c->line = get_next_line(c->map->fd);
		}
		if (!is_valid_data(c->line, c))
		{
			c->map->error = 1;
			return ;
		}
		free(c->line);
		c->line = get_next_line(c->map->fd);
		if (c->map->NO && c->map->SO && c->map->WE &&
			c->map->EA && c->map->C && c->map->F)
			c->data_ok = 1;
	}
	if (!c->data_ok)
		error_data(c);
}
