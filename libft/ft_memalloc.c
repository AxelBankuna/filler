/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abukasa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/18 13:05:40 by abukasa           #+#    #+#             */
/*   Updated: 2017/11/18 13:05:45 by abukasa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void *ptr;

	if (!size)
		return (NULL);
	if (!(ptr = malloc(sizeof(void) * size)))
		return (NULL);
	ft_bzero(ptr, size);
	return (ptr);
}
