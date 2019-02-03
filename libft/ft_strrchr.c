/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abukasa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/10 16:47:45 by abukasa           #+#    #+#             */
/*   Updated: 2017/09/20 09:06:31 by abukasa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_str_len(char *str)
{
	int		index;

	index = 0;
	while (str[index])
		index++;
	return (index);
}

char		*ft_strrchr(const char *s, int c)
{
	int		index;
	char	*str;

	str = (char*)s;
	index = ft_str_len(str);
	while (1)
	{
		if (str[index] == (char)c)
			return (&str[index]);
		if (index == 0 && s[index] != (char)c)
			return (NULL);
		index--;
	}
	return (NULL);
}
