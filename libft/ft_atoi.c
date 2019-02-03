/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abukasa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/20 16:17:03 by abukasa           #+#    #+#             */
/*   Updated: 2017/09/18 14:56:42 by abukasa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_len_str(const char *str)
{
	int		index;

	index = 0;
	while (str[index] == ' ' || str[index] == '\t' || str[index] == '\r'
			|| str[index] == '\v' || str[index] == '\n' || str[index] == '\f')
		index++;
	return (index);
}

int			ft_atoi(const char *str)
{
	int		index;
	int		sign;
	int		ret;

	ret = 0;
	sign = 0;
	index = ft_len_str(str);
	if (str[index] == '-' && (str[index + 1] >= '0' && str[index + 1] <= '9'))
	{
		sign = 1;
		index++;
	}
	if (str[index] == '+')
		index++;
	while (str[index] && (str[index] >= '0' && str[index] <= '9'))
	{
		ret *= 10;
		ret += str[index] - 48;
		index++;
	}
	if (sign == 1)
		ret *= -1;
	return (ret);
}
