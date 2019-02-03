/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trim2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abukasa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/10 13:33:42 by abukasa           #+#    #+#             */
/*   Updated: 2018/08/14 15:56:41 by abukasa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void				trimy2(struct s_piece **temp)
{
	struct s_piece	*temp_hold;
	struct s_piece	*temp_bttm;
	struct s_piece	*temp_next;

	while (*temp)
	{
		temp_hold = (*temp)->left;
		temp_bttm = NULL;
		if ((*temp)->bttm)
		{
			temp_bttm = (*temp)->bttm;
			temp_next = (*temp)->next;
		}
		free(*temp);
		temp_hold->right = NULL;
		if (temp_bttm)
		{
			temp_bttm->top = NULL;
			temp_next->prev = temp_hold;
			temp_hold->next = temp_next;
		}
		else
			temp_hold->next = NULL;
		*temp = temp_bttm;
	}
}

struct s_pieceinfo	trimy(struct s_piece *headpiece,
		struct s_pieceinfo thepiece)
{
	struct s_piece	*temp;

	temp = headpiece;
	while (emptyy(headpiece))
	{
		while (temp->right != NULL)
			temp = temp->right;
		trimy2(&temp);
		thepiece.xlen--;
		temp = headpiece;
	}
	return (thepiece);
}

int					yempty(struct s_piece *headpiece)
{
	struct s_piece	*temp;

	temp = headpiece;
	while (temp->right != NULL)
	{
		if (temp->data != '.')
			return (0);
		temp = temp->right;
	}
	if (temp->data != '.')
		return (0);
	return (1);
}

int					xempty(struct s_piece *headpiece)
{
	struct s_piece	*temp;

	temp = headpiece;
	while (temp->bttm != NULL)
	{
		if (temp->data != '.')
			return (0);
		temp = temp->bttm;
	}
	if (temp->data != '.')
		return (0);
	return (1);
}
