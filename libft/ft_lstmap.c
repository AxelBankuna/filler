/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abukasa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/08 12:42:23 by abukasa           #+#    #+#             */
/*   Updated: 2017/09/18 12:50:06 by abukasa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f) (t_list *elem))
{
	t_list	*new_list;
	t_list	*new_list_item;

	if (lst)
	{
		new_list = f(lst);
		new_list_item = new_list;
		lst = lst->next;
		while (lst)
		{
			new_list_item->next = f(lst);
			new_list_item = new_list_item->next;
			lst = lst->next;
		}
		return (new_list);
	}
	return (NULL);
}
