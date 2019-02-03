/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checking.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abukasa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/10 13:24:52 by abukasa           #+#    #+#             */
/*   Updated: 2018/08/15 16:16:58 by abukasa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void			checkpossible2(struct s_all *all, struct s_mapinfo *mapping,
		struct s_pieceinfo *thepiece, char piece)
{
	struct s_piece	*currentpiece;
	struct s_map	*currentdata;
	int				xy[2];

	xy[0] = 0;
	xy[1] = 0;
	currentdata = *(all->smap);
	currentpiece = *(all->spiece);
	while (xy[1] + thepiece->ylen <= mapping->mapy)
	{
		while (xy[0] + thepiece->xlen <= mapping->mapx)
		{
			if (piececheck(all, xy, piece, *mapping))
				addposs(xy[0] - thepiece->offx, xy[1] - thepiece->offy);
			xy[0]++;
		}
		xy[0] = 0;
		xy[1]++;
	}
}

struct s_poss	*checkpossible(struct s_mapinfo mapping,
		struct s_pieceinfo thepiece)
{
	char			piece;

	if (mapping.player == 1)
	{
		piece = 'O';
		mapping.enemy = 'X';
	}
	else
	{
		piece = 'X';
		mapping.enemy = 'O';
	}
	checkpossible2(all, &mapping, &thepiece, piece);
	if (!headposs)
	{
		addposs(0, 0);
		headposs->exit = 1;
	}
	algo1(&headposs, mapping);
	return (headposs);
}

struct s_all	*all_c_next(struct s_piece **cpiece, struct s_map **cmap)
{
	*(all->cpiece) = (*(all->cpiece))->next;
	*(all->cmap) = (*(all->cmap))->next;
	return (all);
}

int				piececheck2(int *xyp, struct s_all *all,
		struct s_mapinfo *mapping, char piece)
{
	struct s_map	*hold_y;

	while (xyp[1] < thepiece.ylen)
	{
		hold_y = *(all->cmap);
		while (xyp[0] < thepiece.xlen)
		{
			if (((*(all->cmap))->data == mapping->enemy || (*(all->cmap))->data
					== mapping->enemy + 32) && (*(all->cpiece))->data == '*')
				return (0);
			if (((*(all->cmap))->data == piece || (*(all->cmap))->data ==
						piece + 32) && (*(all->cpiece))->data == '*')
				xyp[2]++;
			if (xyp[2] > 1)
				return (0);
			all = all_c_next(all->cpiece, all->cmap);
			xyp[0]++;
		}
		*(all->cmap) = hold_y->bttm;
		xyp[0] = 0;
		xyp[1]++;
	}
	if (xyp[2] != 1)
		return (0);
	return (1);
}

int				piececheck(struct s_all *all, int *xy, char piece,
		struct s_mapinfo mapping)
{
	struct s_piece	*currentpiece;
	struct s_map	*currentdata;
	int				xyp[3];

	xyp[2] = 0;
	currentpiece = *(all->spiece);
	currentdata = *(all->smap);
	while (currentdata->y != xy[1])
		currentdata = currentdata->bttm;
	while (currentdata->x != xy[0])
		currentdata = currentdata->next;
	xyp[0] = 0;
	xyp[1] = 0;
	all->cpiece = &currentpiece;
	all->cmap = &currentdata;
	if (piececheck2(xyp, all, &mapping, piece) == 0)
		return (0);
	return (1);
}
