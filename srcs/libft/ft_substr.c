/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppitzini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 02:08:50 by ppitzini          #+#    #+#             */
/*   Updated: 2024/05/28 15:25:04 by ppitzini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"


char	*ft_substr(char *s, int start, int len)
{
	char	*ptr;
	int		i;

	i = 0;
	ptr = malloc(len + 1);
	if (!ptr)
		return (NULL);
	while (i < len && s[start] != '\0')
	{
		ptr[i] = s[start];
		start++;
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}
