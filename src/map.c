/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abukasa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/10 13:21:38 by abukasa           #+#    #+#             */
/*   Updated: 2018/08/14 15:46:31 by abukasa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void				adddata2(struct s_map **headdata,
		struct s_map **currentdata, struct s_map **newdata)
{
	while ((*currentdata)->next != NULL)
		(*currentdata) = (*currentdata)->next;
	(*currentdata)->next = (*newdata);
	(*newdata)->prev = (*currentdata);
	if ((*newdata)->x == (*currentdata)->x)
	{
		(*currentdata)->right = (*newdata);
		(*newdata)->left = (*currentdata);
	}
	if ((*newdata)->y > 0)
	{
		(*currentdata) = (*headdata);
		while ((*currentdata)->x != (*newdata)->x)
			(*currentdata) = (*currentdata)->next;
		while ((*currentdata)->y != (*newdata)->y - 1)
			(*currentdata) = (*currentdata)->bttm;
		(*currentdata)->bttm = (*newdata);
		(*newdata)->top = (*currentdata);
	}
}

struct s_map		*adddata(int x, int y, char c, struct s_map *headdata)
{
	struct s_map	*currentdata;
	struct s_map	*newdata;

	currentdata = headdata;
	newdata = (struct s_map*)malloc(sizeof(*newdata));
	newdata->data = c;
	newdata->x = x;
	newdata->y = y;
	newdata->right = NULL;
	newdata->bttm = NULL;
	newdata->next = NULL;
	if (y == 0)
		newdata->top = NULL;
	if (x == 0)
		newdata->left = NULL;
	if (headdata == NULL)
	{
		newdata->prev = NULL;
		headdata = newdata;
	}
	else
	{
		adddata2(&headdata, &currentdata, &newdata);
	}
	return (headdata);
}

struct s_mapinfo	play(void)
{
	char	*line;
	char	**split;

	split = NULL;
	line = NULL;
	while (get_next_line(0, &line))
	{
		if (ft_strstr(line, "filler") != NULL)
		{
			split = ft_strsplit(line, ' ');
			mapping.player = split[2][1] - 48;
			return (mapping);
		}
	}
	return (mapping);
}

struct s_mapinfo	board(void)
{
	char	*line;
	char	**split;

	split = NULL;
	line = NULL;
	while (get_next_line(0, &line))
	{
		if (ft_strstr(line, "Plateau") != NULL)
		{
			split = ft_strsplit(line, ' ');
			mapping.mapy = ft_atoi(split[1]);
			mapping.mapx = ft_atoi(split[2]);
			return (mapping);
		}
	}
	return (mapping);
}
