/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abukasa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/05 17:02:28 by abukasa           #+#    #+#             */
/*   Updated: 2017/09/07 16:28:14 by abukasa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*new_link;

	if ((new_link = (t_list*)malloc(sizeof(*new_link))) == NULL)
	{
		return (NULL);
	}
	if (content)
	{
		new_link->content = malloc(content_size);
		if (new_link->content)
			ft_memcpy(new_link->content, content, content_size);
		new_link->content_size = content_size;
	}
	else
	{
		new_link->content = NULL;
		new_link->content_size = 0;
	}
	new_link->next = NULL;
	return (new_link);
}
