/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abukasa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/05 10:42:05 by abukasa           #+#    #+#             */
/*   Updated: 2017/09/18 13:50:20 by abukasa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	int		index;
	char	*str;
	char	*str_ret;

	if (!s)
		return (NULL);
	str = ft_strdup(s);
	if (str)
	{
		index = 0;
		while (str[index] == ' ' || str[index] == '\n' || str[index] == '\t')
			index++;
		str = ft_strcpy(str, str + index);
		index = ft_strlen(str) - 1;
		while ((str[index] == ' ' || str[index] == '\n'
					|| str[index] == '\t') && index >= 0)
		{
			str[index] = '\0';
			index--;
		}
		str_ret = ft_strdup(str);
		free(str);
		return (str_ret);
	}
	return (NULL);
}
