/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redraw.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbraslav <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/22 17:21:19 by mbraslav          #+#    #+#             */
/*   Updated: 2017/09/22 17:21:20 by mbraslav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"
#define MARGIN 1

static size_t	get_max_len(t_list *list)
{
	size_t	max;
	size_t	len;

	max = 0;
	while (list)
	{
		len = ft_strlen(((t_entry *)list->content)->content);
		max = (max < len) ? len : max;
		list = list->next;
	}
	return (max);
}

static void		print_entry(int fd, t_entry *entry, size_t width)
{
	short	spaces;
	size_t	len;

	len = ft_strlen(entry->content);
	spaces = width - len;
	color(fd, entry->content);
	if (entry->selected)
		ft_putstr_fd(tgetstr("us", NULL), fd);
	if (entry->cursor)
		ft_putstr_fd(tgetstr("mr", NULL), fd);
	write(fd, entry->content, len);
	ft_putstr_fd(tgetstr("me", NULL), fd);
	while (spaces--)
		write(fd, " ", 1);
}

static void		print_list(t_list *list, int fd, size_t width, \
							struct winsize table)
{
	t_list	*elem;
	size_t	i;
	size_t	j;

	j = 0;
	while (j < table.ws_row)
	{
		i = 0;
		while (i < table.ws_col)
		{
			if ((elem = ft_lstgetelem(list, i * table.ws_row + j)))
				print_entry(fd, elem->content, width);
			i++;
			if (!(i % table.ws_col) && !((j + 1) == table.ws_row))
				write(fd, "\n", 1);
		}
		j++;
	}
}

static void		draw_columns(int fd, t_list *list, struct winsize ws)
{
	struct winsize	table;
	size_t			width;
	size_t			lstlen;

	lstlen = ft_lstlen(list);
	width = get_max_len(list) + MARGIN;
	table.ws_col = ws.ws_col / width;
	table.ws_col = (table.ws_col > lstlen) ? lstlen : table.ws_col;
	table.ws_row = (table.ws_col) ? lstlen / table.ws_col : 0;
	table.ws_row += \
			(table.ws_row && table.ws_row * table.ws_col < lstlen) ? 1 : 0;
	if (!table.ws_col || !table.ws_row || \
		width * table.ws_col > ws.ws_col || table.ws_row > ws.ws_row)
	{
		write(fd, "window is too small", 19);
		return ;
	}
	print_list(list, fd, width, table);
}

void			redraw_window(int fd, t_list *list)
{
	struct winsize	ws;

	if (ioctl(fd, TIOCGWINSZ, &ws))
	{
		ft_putstr_fd(tgetstr("ve", NULL), fd);
		ft_putstr_fd(tgetstr("te", NULL), fd);
		terminate("ft_select", "can't get window size");
	}
	ft_putstr_fd(tgetstr("cl", NULL), fd);
	draw_columns(fd, list, ws);
}
