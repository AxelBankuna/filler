/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abukasa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/24 17:25:11 by abukasa           #+#    #+#             */
/*   Updated: 2017/09/18 11:32:00 by abukasa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	int		len;
	char	*str;

	len = 0;
	if (s && f)
	{
		while (s[len])
			len++;
		if ((str = (char*)malloc(sizeof(*str) * (len + 1))) == NULL)
			return (NULL);
		str[len + 1] = '\0';
		len = 0;
		while (s[len])
		{
			str[len] = f(s[len]);
			len++;
		}
		str[len] = '\0';
		return (str);
	}
	return (NULL);
}
