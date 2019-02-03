/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abukasa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/10 13:17:37 by abukasa           #+#    #+#             */
/*   Updated: 2018/08/14 15:36:50 by abukasa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

struct s_map	**createmap(struct s_map *headdata)
{
	char				*line;
	int					y;
	int					x;
	int					i;
	static struct s_map	**address = NULL;

	i = 4;
	line = NULL;
	x = 0;
	y = 0;
	get_next_line(0, &line);
	while (get_next_line(0, &line) && y < mapping.mapy)
	{
		while (line[i] != '\0')
		{
			x = i - 4;
			headdata = adddata(x, y, line[i], headdata);
			i++;
		}
		i = 4;
		y++;
	}
	thepiece = (getpieceinfo(line));
	address = &headdata;
	return (address);
}

struct s_piece	**createpiece(struct s_piece *headpiece)
{
	char					*line;
	int						y;
	int						x;
	static struct s_piece	**address = NULL;

	line = NULL;
	x = 0;
	y = 0;
	while (y < thepiece.ylen)
	{
		get_next_line(0, &line);
		while (line[x] != '\0')
		{
			headpiece = addpiece(x, y, line[x], headpiece);
			x++;
		}
		x = 0;
		y++;
	}
	address = &headpiece;
	return (address);
}
