/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abukasa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/04 15:55:54 by abukasa           #+#    #+#             */
/*   Updated: 2017/09/18 11:19:21 by abukasa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

int		ft_strequ(char const *s1, char const *s2)
{
	int		index;

	index = 0;
	if (s1 == NULL || s2 == NULL || (ft_strlen(s1) != ft_strlen(s2)))
		return (0);
	while (s1[index] && s2[index] && s1[index] == s2[index])
	{
		index++;
	}
	if (s1[index] == s2[index])
		return (1);
	return (0);
}
