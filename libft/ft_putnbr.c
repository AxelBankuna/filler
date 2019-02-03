/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abukasa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/22 18:25:04 by abukasa           #+#    #+#             */
/*   Updated: 2017/09/18 11:14:41 by abukasa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(int n)
{
	unsigned long	n_long;

	if (n >= 0)
		n_long = (unsigned long)n;
	else
	{
		ft_putchar('-');
		n_long = (unsigned long)n * (-1);
	}
	if (n_long >= 10)
	{
		ft_putnbr(n_long / 10);
		n_long %= 10;
	}
	ft_putchar(n_long + 48);
}
