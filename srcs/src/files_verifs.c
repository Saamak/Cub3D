/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   files_verifs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppitzini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 16:21:56 by ppitzini          #+#    #+#             */
/*   Updated: 2024/07/01 16:21:58 by ppitzini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

int	file_exists(char *filename)
{
	int	fd;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		printf(B_R"   | Error : File %s does not exist \u274c \n\n"
			RESET, filename);
		printf(BOLD END_LINE RESET);
		return (0);
	}
	else
	{
		printf(B_G"   |File %s exists \xE2\x9C\x93 \n\n"RESET, filename);
		close(fd);
		return (1);
	}
}
