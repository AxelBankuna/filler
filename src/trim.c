/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trim.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abukasa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/10 13:32:01 by abukasa           #+#    #+#             */
/*   Updated: 2018/08/14 15:54:50 by abukasa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int					emptyy(struct s_piece *headpiece)
{
	struct s_piece	*temp;

	temp = headpiece;
	while (temp->right != NULL)
		temp = temp->right;
	if (temp->data != '.')
		return (0);
	if (temp->bttm != NULL)
	{
		while (temp->bttm != NULL)
		{
			if (temp->data != '.')
				return (0);
			temp = temp->bttm;
		}
	}
	if (temp->data != '.')
	{
		return (0);
	}
	return (1);
}

int					emptyx(struct s_piece *headpiece)
{
	struct s_piece	*temp;

	temp = headpiece;
	while (temp->bttm != NULL)
		temp = temp->bttm;
	if (temp->data != '.')
		return (0);
	if (temp->right != NULL)
	{
		while (temp->right != NULL)
		{
			if (temp->data != '.')
				return (0);
			temp = temp->right;
		}
	}
	if (temp->data != '.')
	{
		return (0);
	}
	return (1);
}

void				trimx2(struct s_piece **temp)
{
	struct s_piece	*temp_hold;
	struct s_piece	*temp_top;

	while (*temp)
	{
		temp_top = (*temp)->top;
		temp_hold = NULL;
		if ((*temp)->left)
		{
			(*temp)->left->next = NULL;
			temp_hold = (*temp)->left;
		}
		(*temp)->prev->next = NULL;
		free(*temp);
		temp_top->bttm = NULL;
		if (temp_hold)
			temp_hold->next = NULL;
		*temp = temp_hold;
	}
}

struct s_pieceinfo	trimx(struct s_piece *headpiece,
		struct s_pieceinfo thepiece)
{
	struct s_piece	*temp;

	temp = headpiece;
	while (emptyx(headpiece))
	{
		while (temp->next != NULL)
			temp = temp->next;
		trimx2(&temp);
		temp = headpiece;
		thepiece.ylen--;
	}
	return (thepiece);
}
