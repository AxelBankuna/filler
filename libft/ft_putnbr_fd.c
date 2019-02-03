/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abukasa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/22 18:25:04 by abukasa           #+#    #+#             */
/*   Updated: 2017/09/16 18:04:01 by abukasa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char			c;
	unsigned long	n_long;

	if (n >= 0)
		n_long = (unsigned long)n;
	else
	{
		write(fd, "-", 1);
		n_long = (unsigned long)n * (-1);
	}
	if (n_long >= 10)
	{
		ft_putnbr_fd(n_long / 10, fd);
		n_long %= 10;
	}
	c = n_long + 48;
	write(fd, &c, 1);
}
