/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abukasa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/10 13:37:29 by abukasa           #+#    #+#             */
/*   Updated: 2018/08/14 16:03:12 by abukasa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	switchposs(struct s_poss **temp)
{
	struct s_poss	*current;
	int				tempx;
	int				tempy;

	current = *temp;
	current = current->next;
	tempx = (*temp)->x;
	tempy = (*temp)->y;
	(*temp)->x = current->x;
	(*temp)->y = current->y;
	current->x = tempx;
	current->y = tempy;
}

int		ifcenter(int a, int b)
{
	if (a > b)
		return (0);
	return (1);
}

int		ftpow(int nbr, int pow)
{
	if (nbr == 0)
		return (1);
	if (pow == 0)
		return (1);
	return (nbr * ftpow(nbr, pow - 1));
}

double	ftsq(int num)
{
	double x1;
	double x2;

	x1 = (num * 1.0) / 2;
	x2 = (x1 + (num / x1)) / 2;
	while ((x1 - x2) >= 0.0000001)
	{
		x1 = x2;
		x2 = (x1 + (num / x1)) / 2;
	}
	return (x2);
}

void	algo1(struct s_poss **headposs, struct s_mapinfo mapping)
{
	struct s_poss	*current;
	int				centerx;
	int				centery;
	int				ca;
	int				cb;

	current = *headposs;
	centerx = mapping.mapx / 2;
	centery = mapping.mapy / 2;
	while (current->next != NULL)
	{
		ca = (int)ftsq(ftpow((current->x - centerx), 2) +
				ftpow((current->y - centery), 2));
		cb = (int)ftsq(ftpow((current->next->x - centerx), 2) +
				ftpow((current->next->y - centery), 2));
		if (!ifcenter(ca, cb))
		{
			switchposs(&current);
			current = *headposs;
		}
		else
			current = current->next;
	}
}
