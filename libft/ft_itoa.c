/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abukasa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/18 10:25:06 by abukasa           #+#    #+#             */
/*   Updated: 2017/09/18 10:34:10 by abukasa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_size_len(int n)
{
	size_t	index;

	index = 1;
	while (n /= 10)
		index++;
	return (index);
}

char			*ft_itoa(int n)
{
	char			*str;
	size_t			len;
	unsigned int	temp_n;

	len = ft_size_len(n);
	temp_n = n;
	if (n < 0)
	{
		temp_n = -n;
		len++;
	}
	if (!(str = ft_strnew(len)))
		return (NULL);
	str[--len] = temp_n % 10 + '0';
	while (temp_n /= 10)
		str[--len] = temp_n % 10 + '0';
	if (n < 0)
		*(str + 0) = '-';
	return (str);
}
