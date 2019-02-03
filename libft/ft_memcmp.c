/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abukasa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/04 18:23:48 by abukasa           #+#    #+#             */
/*   Updated: 2017/06/09 21:02:50 by abukasa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*str1;
	unsigned char	*str2;
	size_t			index;

	index = 0;
	str1 = (unsigned char*)s1;
	str2 = (unsigned char*)s2;
	while (index < n)
	{
		if (str1[index] == str2[index])
			index++;
		else
			return (str1[index] - str2[index]);
	}
	return (0);
}
