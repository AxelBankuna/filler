/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abukasa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/04 15:18:53 by abukasa           #+#    #+#             */
/*   Updated: 2017/09/18 12:43:07 by abukasa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*dest;
	const char	*source;
	int			index;

	dest = dst;
	source = src;
	if (dest > source)
	{
		index = (int)len - 1;
		while (index >= 0)
		{
			dest[index] = source[index];
			index--;
		}
	}
	else if (dest < source)
	{
		index = 0;
		while ((int)len > index)
		{
			dest[index] = source[index];
			index++;
		}
	}
	return (dest);
}
