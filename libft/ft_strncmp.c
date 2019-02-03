/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abukasa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/18 10:42:21 by abukasa           #+#    #+#             */
/*   Updated: 2017/09/20 16:07:55 by abukasa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			index;
	unsigned char	*str1;
	unsigned char	*str2;

	index = 0;
	str1 = (unsigned char*)s1;
	str2 = (unsigned char*)s2;
	if (!n)
		return (0);
	if (*str1 != *str2)
		return (*str1 - *str2);
	if (*s1 == '\0' && *s2 == '\0')
		return (0);
	while (index < (n - 1) && str1[index] != '\0' && str2[index] != '\0'
			&& str1[index] == str2[index])
		index++;
	return (str1[index] - str2[index]);
}
