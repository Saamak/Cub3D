/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppitzini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 17:08:33 by ppitzini          #+#    #+#             */
/*   Updated: 2024/05/28 15:21:18 by ppitzini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

int	count_words(char const *s, char c)
{
	int	c_w;
	int	tmp;

	tmp = 0;
	c_w = 0;
	while (*s != '\0')
	{
		if (tmp == 1 && *s == c)
			tmp = 0;
		if (tmp == 0 && *s != c)
		{
			tmp = 1;
			c_w++;
		}
		s++;
	}
	return (c_w);
}

char	**ft_split(char *s, char c, t_map *map)
{
	char	**dest;
	int		x;

	x = 0;
	if (!s)
		return (NULL);
	dest = malloc(sizeof(char *) * (count_words(s, c) + 1));
	if (!dest)
		return (NULL);
	while (*s)
	{
		if (s[0] == c)
			s++;
		else
		{
			map->i = 0;
			while (s[map->i] != '\0' && s[map->i] != c)
				map->i++;
			dest[x++] = ft_substr(s, 0, map->i);
			s = s + map->i;
		}
	}
	dest[x] = NULL;
	return (dest);
}
