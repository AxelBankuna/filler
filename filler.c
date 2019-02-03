/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abukasa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/17 14:27:02 by abukasa           #+#    #+#             */
/*   Updated: 2018/08/15 15:22:30 by abukasa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "src/filler.h"

int		main(void)
{
	init_mapping(&mapping);
	mapping = play();
	while (1)
	{
		headdata = NULL;
		headpiece = NULL;
		headposs = NULL;
		newposs = NULL;
		currentposs = NULL;
		all = NULL;
		all = init_all(&headdata, &headpiece, all);
		init_mapping(&mapping);
		init_piece(&thepiece);
		mapping = board();
		headdata = *createmap(*(all->smap));
		headpiece = *createpiece(headpiece);
		trimpiece(&headpiece, &thepiece);
		headposs = checkpossible(mapping, thepiece);
		placepiece(headposs->y, headposs->x);
		if (headposs->exit)
			return (0);
		freeall(&headpiece, &headdata, &headposs);
	}
	return (0);
}
