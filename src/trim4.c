/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trim3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abukasa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/10 13:35:01 by abukasa           #+#    #+#             */
/*   Updated: 2018/08/14 16:08:07 by abukasa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	trimpiece(struct s_piece **headpiece, struct s_pieceinfo *thepiece)
{
	*thepiece = trimx(*headpiece, *thepiece);
	*thepiece = trimy(*headpiece, *thepiece);
	*thepiece = ytrim(headpiece, *thepiece);
	*thepiece = xtrim(headpiece, *thepiece);
}
