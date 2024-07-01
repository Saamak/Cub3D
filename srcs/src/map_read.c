/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_read.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppitzini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 16:24:07 by ppitzini          #+#    #+#             */
/*   Updated: 2024/07/01 16:25:48 by ppitzini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

void	check_map_start(t_core *c)
{
	if (!c->line || c->line[0] != '\n')
	{
		c->map->error = 1;
		printf(B_R ERROR_SYNTAX RESET);
		printf(BOLD END_LINE RESET);
		free_parsing(c);
		exit(0);
	}
	while (c->line && c->line[0] == '\n' && !its_map(c->line))
	{
		free(c->line);
		c->line = get_next_line(c->map->fd);
	}
	if (!c->line)
	{
		c->map->error = 1;
		printf(B_R ERROR_SYNTAX RESET);
		printf(BOLD END_LINE RESET);
		free_parsing(c);
		exit(0);
	}
}

void	skip_lines(int fd, t_core *c)
{
	c->line = get_next_line(fd);
	while (c->line && c->line[0] == '\n')
	{
		free(c->line);
		c->line = get_next_line(fd);
		if (!c->line)
		{
			c->map->error = 1;
			printf(B_R ERROR_EMPTY_MAP RESET);
			printf(BOLD END_LINE RESET);
			return ;
		}
	}
}

int	read_hub(t_core *c)
{
	c->map->fd = open(c->map->map_path, O_RDONLY);
	if (c->map->fd == -1)
	{
		printf(B_R ERROR_OPEN_FILE RESET);
		printf(BOLD END_LINE RESET);
		c->map->error = 1;
		return (0);
	}
	skip_lines(c->map->fd, c);
	take_map_data(c);
	if (!c->map->error && c->data_ok)
	{
		printf(B_G"\n\n-----------------| Data are corrects \xE2\x9C\x93 |-------------\n"RESET);
		check_map_start(c);
	}
	return (1);
}
