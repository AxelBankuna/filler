/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abukasa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/20 13:34:33 by abukasa           #+#    #+#             */
/*   Updated: 2017/09/20 13:40:56 by abukasa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t			index;
	unsigned char	*dest;
	unsigned char	*source;
	unsigned char	ch;

	index = 0;
	dest = (unsigned char *)dst;
	source = (unsigned char *)src;
	ch = (unsigned char)c;
	while (index < n)
	{
		dest[index] = source[index];
		if (source[index] == ch)
			return (dest + index + 1);
		index++;
	}
	return (NULL);
}
