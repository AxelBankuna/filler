/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abukasa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/04 17:23:05 by abukasa           #+#    #+#             */
/*   Updated: 2017/09/18 15:03:04 by abukasa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*str;
	size_t			index;

	index = 0;
	str = (unsigned char*)s;
	while (index < n)
	{
		if (str[index] == (unsigned char)c)
			return (str + index);
		index++;
	}
	return (NULL);
}
