/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppitzini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 19:09:34 by ppitzini          #+#    #+#             */
/*   Updated: 2023/11/03 19:36:05 by ppitzini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	lend;

	lend = 0;
	i = 0;
	if (size == 0)
		return (ft_strlen(src));
	while (src[i] != '\0' && i < size -1)
	{
		dst[i] = src[i];
		i++;
	}
	if (size >= lend)
		dst[i] = '\0';
	if (size < ft_strlen(dst))
		return (ft_strlen(src) + size);
	else
		return (ft_strlen(src) + lend);
}
