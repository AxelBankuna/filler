/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abukasa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/10 18:19:38 by abukasa           #+#    #+#             */
/*   Updated: 2018/07/14 14:41:33 by abukasa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static int	ft_str_len(char *str)
{
	int	index;

	index = 0;
	while (str[index])
		index++;
	return (index);
}

char		*ft_strstr(const char *big, const char *little)
{
	int		i;
	int		j;

	i = 0;
	if (ft_str_len((char*)little) == 0 && ft_str_len((char*)(big)) == 0)
		return ((char*)big);
	if (little == NULL && big != NULL)
		return ((char*)big);
	while (big[i])
	{
		j = 0;
		while (big[i + j] == little[j] && big[i + j] && little[j])
		{
			j++;
		}
		if (little[j] == '\0')
			return ((char *)big + i);
		i++;
	}
	return (NULL);
}
