/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abukasa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/10 13:28:25 by abukasa           #+#    #+#             */
/*   Updated: 2018/08/14 15:44:10 by abukasa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	free_piece(struct s_piece **headpiece)
{
	struct s_piece	*next_link;
	struct s_piece	*currentpiece;

	currentpiece = *headpiece;
	while (currentpiece)
	{
		next_link = currentpiece->next;
		free(currentpiece);
		currentpiece = next_link;
	}
	*headpiece = NULL;
}

void	free_map(struct s_map **headdata)
{
	struct s_map	*currentdata;
	struct s_map	*next_link;

	currentdata = *headdata;
	while (currentdata)
	{
		next_link = currentdata->next;
		free(currentdata);
		currentdata = next_link;
	}
	*headdata = NULL;
}

void	free_poss(struct s_poss **headposs)
{
	struct s_poss	*next_link;

	currentposs = *headposs;
	while (currentposs)
	{
		next_link = currentposs->next;
		free(currentposs);
		currentposs = next_link;
	}
	*headposs = NULL;
}

void	freeall(struct s_piece **headpiece,
		struct s_map **headdata, struct s_poss **headposs)
{
	free_piece(headpiece);
	free_map(headdata);
	free_poss(headposs);
}
