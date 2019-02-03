/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checking2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abukasa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/10 13:26:22 by abukasa           #+#    #+#             */
/*   Updated: 2018/08/10 13:26:50 by abukasa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

struct s_poss		*addposs(int x, int y)
{
	newposs = (struct s_poss*)malloc(sizeof(*newposs));
	newposs->x = x;
	newposs->y = y;
	newposs->exit = 0;
	newposs->next = NULL;
	if (headposs == NULL)
		headposs = newposs;
	else
	{
		currentposs = headposs;
		while (currentposs->next != NULL)
			currentposs = currentposs->next;
		currentposs->next = newposs;
	}
	return (headposs);
}

char				mypiece(struct s_map *headdata)
{
	struct s_map	*currentdata;

	currentdata = headdata;
	while (currentdata->next != NULL)
	{
		if (currentdata->data == 'o')
			return ('O');
		if (currentdata->data == 'x')
			return ('X');
		currentdata = currentdata->next;
	}
	return ('O');
}
