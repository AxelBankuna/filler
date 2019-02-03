/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trim3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abukasa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/10 13:35:01 by abukasa           #+#    #+#             */
/*   Updated: 2018/08/14 16:07:36 by abukasa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void				ytrim2(struct s_piece **temp, struct s_piece **headpiece)
{
	struct s_piece	*temp_hold;
	struct s_piece	*temp_bttm;
	struct s_piece	*temp_next;

	while (*temp)
	{
		temp_hold = NULL;
		temp_bttm = (*temp)->bttm;
		temp_next = (*temp)->next;
		if ((*temp)->right)
		{
			temp_hold = (*temp)->right;
			temp_hold->left = NULL;
		}
		temp_bttm->top = NULL;
		free(*temp);
		temp_next->prev = NULL;
		*temp = temp_hold;
		*headpiece = temp_next;
	}
}

struct s_pieceinfo	ytrim(struct s_piece **headpiece,
		struct s_pieceinfo thepiece)
{
	struct s_piece	*temp;

	temp = *headpiece;
	while (yempty(*headpiece))
	{
		ytrim2(&temp, headpiece);
		temp = *headpiece;
		thepiece.ylen--;
		thepiece.offy++;
	}
	return (thepiece);
}

void				xtrim22(struct s_piece **temp)
{
	(*temp)->prev->next = (*temp)->next;
	(*temp)->next->prev = (*temp)->prev;
}

void				xtrim2(struct s_piece **temp, struct s_piece **headpiece,
		struct s_piece *temp_hold, struct s_piece *temp_bttm)
{
	struct s_piece	*temp_right;

	while (*temp)
	{
		temp_bttm = NULL;
		if ((*temp)->bttm != NULL)
		{
			temp_bttm = (*temp)->bttm;
			temp_bttm->top = NULL;
		}
		if ((*temp)->right != NULL)
		{
			temp_right = (*temp)->right;
			temp_right->left = NULL;
		}
		if ((*temp)->prev == NULL)
			*headpiece = temp_hold;
		else
		{
			xtrim22(temp);
		}
		temp_hold->prev = NULL;
		free(*temp);
		*temp = temp_bttm;
	}
}

struct s_pieceinfo	xtrim(struct s_piece **headpiece,
		struct s_pieceinfo thepiece)
{
	struct s_piece	*temp;
	struct s_piece	*temp_hold;
	struct s_piece	*temp_bttm;

	temp_bttm = NULL;
	temp = *headpiece;
	while (xempty(*headpiece))
	{
		temp_hold = temp->next;
		xtrim2(&temp, headpiece, temp_hold, temp_bttm);
		temp = *headpiece;
		thepiece.xlen--;
		thepiece.offx++;
	}
	return (thepiece);
}
