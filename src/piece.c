/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   piece.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abukasa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/10 13:19:45 by abukasa           #+#    #+#             */
/*   Updated: 2018/08/14 15:48:49 by abukasa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void				addpiece2(struct s_piece **currentpiece,
		struct s_piece **newpiece, struct s_piece **headpiece)
{
	while ((*currentpiece)->next != NULL)
		(*currentpiece) = (*currentpiece)->next;
	(*currentpiece)->next = (*newpiece);
	(*newpiece)->prev = (*currentpiece);
	if ((*newpiece)->y == (*currentpiece)->y)
	{
		(*currentpiece)->right = (*newpiece);
		(*newpiece)->left = (*currentpiece);
	}
	if ((*newpiece)->y > 0)
	{
		(*currentpiece) = (*headpiece);
		while ((*currentpiece)->y != (*newpiece)->y - 1)
			(*currentpiece) = (*currentpiece)->bttm;
		while ((*currentpiece)->x != (*newpiece)->x)
			(*currentpiece) = (*currentpiece)->right;
		(*currentpiece)->bttm = (*newpiece);
		(*newpiece)->top = (*currentpiece);
	}
}

struct s_piece		*addpiece(int x, int y, char c, struct s_piece *headpiece)
{
	struct s_piece	*currentpiece;
	struct s_piece	*newpiece;

	currentpiece = headpiece;
	newpiece = (struct s_piece*)malloc(sizeof(*newpiece));
	newpiece->data = c;
	newpiece->x = x;
	newpiece->y = y;
	newpiece->right = NULL;
	newpiece->bttm = NULL;
	newpiece->next = NULL;
	if (y == 0)
		newpiece->top = NULL;
	if (x == 0)
		newpiece->left = NULL;
	if (headpiece == NULL)
	{
		newpiece->prev = NULL;
		headpiece = newpiece;
	}
	else
	{
		addpiece2(&currentpiece, &newpiece, &headpiece);
	}
	return (headpiece);
}

struct s_pieceinfo	getpieceinfo(char *line)
{
	char	**split;

	split = ft_strsplit(line, ' ');
	thepiece.xlen = ft_atoi(split[2]);
	thepiece.ylen = ft_atoi(split[1]);
	return (thepiece);
}
