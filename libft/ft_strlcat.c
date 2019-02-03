/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abukasa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/18 16:21:16 by abukasa           #+#    #+#             */
/*   Updated: 2017/09/18 16:25:34 by abukasa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	index;
	size_t	dst_len;
	size_t	src_len;

	index = 0;
	src_len = ft_strlen(src);
	while (dst[index] && index < size)
		index++;
	dst_len = index;
	if ((size - index) == 0)
		return (index + src_len);
	while (src[index - dst_len] && index < size - 1)
	{
		dst[index] = src[index - dst_len];
		index++;
	}
	if (dst_len < size)
		dst[index] = '\0';
	return (dst_len + src_len);
}
