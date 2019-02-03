/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abukasa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/10 13:22:59 by abukasa           #+#    #+#             */
/*   Updated: 2018/08/14 15:50:13 by abukasa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	printmap(struct s_map *headdata)
{
	struct s_map	*currentdata;

	currentdata = headdata;
	while (currentdata->next != NULL)
	{
		if (currentdata != headdata)
		{
			if (currentdata->y != currentdata->prev->y)
				printf("\n");
		}
		printf("%c", currentdata->data);
		currentdata = currentdata->next;
	}
	printf("%c", currentdata->data);
	printf("\n");
}

void	printpiece(struct s_piece *headpiece)
{
	struct s_piece	*currentpiece;

	currentpiece = headpiece;
	while (currentpiece->next != NULL)
	{
		if (currentpiece != headpiece)
		{
			if (currentpiece->y != currentpiece->prev->y)
				printf("\n");
		}
		printf("%c", currentpiece->data);
		currentpiece = currentpiece->next;
	}
	if (currentpiece->y != currentpiece->prev->y)
		printf("\n");
	printf("%c", currentpiece->data);
	printf("\n");
}

void	printposs(struct s_poss *headposs)
{
	currentposs = headposs;
	while (currentposs->next != NULL)
	{
		printf("x=%d\ty=%d\n", currentposs->x, currentposs->y);
		currentposs = currentposs->next;
	}
	printf("x=%d\ty=%d\n", currentposs->x, currentposs->y);
}

void	placepiece(int y, int x)
{
	ft_putnbr_fd(y, 1);
	write(1, " ", 1);
	ft_putnbr_fd(x, 1);
	write(1, "\n", 1);
}
