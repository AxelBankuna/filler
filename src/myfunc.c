/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   myfunc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abukasa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/31 16:41:01 by abukasa           #+#    #+#             */
/*   Updated: 2018/07/31 18:41:06 by abukasa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

struct s_pieceinfo	trimx(struct s_piece *headpiece, struct s_pieceinfo thepiece)
{
	struct s_piece	*temp;
	struct s_piece	*temp_hold;
	struct s_piece	*temp_top;

	temp = headpiece;
	while (emptyx(headpiece))
	{
		while (temp->next != NULL)
			temp = temp->next;
		while (temp)
		{
			temp_hold = NULL;
			if (temp->left)
			{
				temp->left->next = NULL;
				temp_hold = temp->left;
			}
			temp->prev->next = NULL;
			free(temp);
			temp_top->bttm = NULL;
			temp_hold->next = NULL;
			temp = temp->hold;
		}
		temp = headpiece;
		thepiece.ylen--;
	}
	return (thepiece);
}
