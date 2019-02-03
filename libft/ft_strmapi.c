/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abukasa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/18 11:32:59 by abukasa           #+#    #+#             */
/*   Updated: 2017/09/18 11:33:21 by abukasa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	len;
	char			*str;

	if (s && f)
	{
		len = 0;
		while (s[len])
			len++;
		if ((str = (char*)malloc(sizeof(char) * (len + 1))) == NULL)
			return (NULL);
		len = 0;
		while (s[len])
		{
			str[len] = f(len, s[len]);
			len++;
		}
		str[len] = '\0';
		return (str);
	}
	return (NULL);
}
