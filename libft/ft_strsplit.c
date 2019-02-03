/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abukasa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/08 16:10:48 by abukasa           #+#    #+#             */
/*   Updated: 2018/07/14 14:25:06 by abukasa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_space(char c, char deli)
{
	if (c == deli)
		return (1);
	else
		return (0);
}

static char	*ft_retword(char *str, int index, char c)
{
	int		len;
	char	*retword;

	len = 0;
	while (ft_isprint(str[index]) && str[index] != c)
	{
		len++;
		index++;
	}
	index--;
	len--;
	retword = (char*)malloc(sizeof(char) * (len + 1));
	retword[len + 1] = '\0';
	while (len >= 0)
		retword[len--] = str[index--];
	return (retword);
}

static char	**ft_splitting(int wd_count, int index, char c, char const *s)
{
	char	**arr_str;
	int		word;

	word = 0;
	if ((arr_str = (char**)malloc(sizeof(char*) * (wd_count + 1))) == NULL)
		return (NULL);
	index = 0;
	while (ft_space(s[index], c))
		index++;
	while (word < wd_count)
	{
		arr_str[word] = ft_retword((char*)s, index, c);
		while (ft_isprint(s[index]) && s[index] != c)
			index++;
		while (ft_space(s[index], c))
			index++;
		word++;
	}
	arr_str[word] = NULL;
	return (arr_str);
}

char		**ft_strsplit(char const *s, char c)
{
	int		wd_count;
	int		index;

	wd_count = 0;
	index = 0;
	if (!s || !c)
		return (NULL);
	while (ft_space(s[index], c))
		index++;
	while (s[index])
	{
		while (ft_isprint(s[index]) && s[index] != c)
			index++;
		wd_count++;
		while (ft_space(s[index], c))
			index++;
	}
	return (ft_splitting(wd_count, index, c, s));
}
