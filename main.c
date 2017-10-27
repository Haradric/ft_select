/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbraslav <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/22 17:21:30 by mbraslav          #+#    #+#             */
/*   Updated: 2017/09/22 17:21:31 by mbraslav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

struct termios	*g_settings;

static void	init(struct termios *settings)
{
	char	*termtype;
	int		success;

	termtype = getenv("TERM");
	if (!termtype)
		terminate("ft_select", "Specify a terminal type with 'setenv TERM \
				termtype'");
	success = tgetent(NULL, termtype);
	if (success < 0)
		terminate("ft_select", "Could not access the termcap data base");
	else if (success == 0)
		terminate("ft_select: Terminal type is not defined", termtype);
	tcgetattr(0, &settings[DFL]);
	settings[MOD] = settings[DFL];
	settings[MOD] = *settings;
	settings[MOD].c_lflag &= (~ICANON & ~ECHO);
	settings[MOD].c_cc[VTIME] = 0;
	settings[MOD].c_cc[VMIN] = 1;
}

static void	print_entry(t_list *elem)
{
	static char	first = 1;
	t_entry		*entry;

	entry = elem->content;
	if (entry->selected)
	{
		if (!first)
			write(1, " ", 1);
		else
			first = 0;
		write(1, entry->content, ft_strlen(entry->content));
	}
}

int			main(int argc, const char **argv)
{
	struct termios	settings[2];
	t_list			*list;

	sleep(1);
	if (argc == 1)
		terminate("ft_select", "need some arguments");
	init(settings);
	g_settings = settings;
	list = ft_select(argv);
	ft_lstiter(list, print_entry);
	ft_lstfreelist(&list, free);
	return (EXIT_SUCCESS);
}
