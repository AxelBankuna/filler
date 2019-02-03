/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abukasa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/18 13:06:03 by abukasa           #+#    #+#             */
/*   Updated: 2017/11/18 13:06:08 by abukasa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int data, size_t byte)
{
	size_t i;

	i = 0;
	while (i < byte)
	{
		*(unsigned char *)(b + i) = (unsigned char)(data);
		i++;
	}
	return (b);
}
