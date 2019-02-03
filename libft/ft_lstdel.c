/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abukasa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/08 11:08:30 by abukasa           #+#    #+#             */
/*   Updated: 2017/09/08 11:20:04 by abukasa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del) (void*, size_t))
{
	t_list	*current;
	t_list	*next_link;

	current = *alst;
	while (current)
	{
		del(current->content, current->content_size);
		next_link = current->next;
		free(current);
		current = next_link;
	}
	*alst = NULL;
}
