/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbraslav <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/22 17:21:57 by mbraslav          #+#    #+#             */
/*   Updated: 2017/09/22 17:21:57 by mbraslav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	navigate(t_list *list, long key)
{
	t_list	*elem;

	if (!list)
		return ;
	elem = list;
	while (elem && !((t_entry *)elem->content)->cursor)
		elem = elem->next;
	((t_entry *)elem->content)->cursor = 0;
	if (key == KEY_UP)
		elem = (!elem->prev) ? ft_lstgetlast(list) : elem->prev;
	else
		elem = (!elem->next) ? list : elem->next;
	((t_entry *)elem->content)->cursor = 1;
}

void	mark(t_list *list)
{
	t_list	*elem;
	t_entry	*entry;

	if (!list)
		return ;
	elem = list;
	while (elem && !((t_entry *)elem->content)->cursor)
		elem = elem->next;
	entry = elem->content;
	entry->cursor = 0;
	entry->selected = !entry->selected;
	elem = (!elem->next) ? list : elem->next;
	((t_entry *)elem->content)->cursor = 1;
}

void	diselect_all(t_list *list)
{
	if (!list)
		return ;
	while (list)
	{
		((t_entry *)list->content)->selected = 0;
		list = list->next;
	}
}

void	delete(t_list **list)
{
	t_list	*elem;
	t_entry	*entry;

	if (!list || !*list)
		return ;
	elem = *list;
	while (elem && !((t_entry *)elem->content)->cursor)
		elem = elem->next;
	entry = (elem->next) ? elem->next->content : (*list)->content;
	entry->cursor = 1;
	ft_lstfreeelem(list, elem, free);
}
