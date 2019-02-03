/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abukasa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/10 13:29:55 by abukasa           #+#    #+#             */
/*   Updated: 2018/08/15 15:11:21 by abukasa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void			init_mapping(struct s_mapinfo *m)
{
	m->mapy = 0;
	m->mapx = 0;
	m->myy = 0;
	m->myx = 0;
	m->enemyy = 0;
	m->enemyx = 0;
}

void			init_piece(struct s_pieceinfo *p)
{
	p->xlen = 0;
	p->ylen = 0;
	p->offy = 0;
	p->offx = 0;
}

struct s_all	*init_all(struct s_map **headdata,
		struct s_piece **headpiece, struct s_all *all)
{
	all = (struct s_all*)malloc(sizeof(*all));
	all->smap = headdata;
	all->spiece = headpiece;
	return (all);
}
