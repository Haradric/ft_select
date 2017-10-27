/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbraslav <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/22 17:21:41 by mbraslav          #+#    #+#             */
/*   Updated: 2017/09/22 17:21:41 by mbraslav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

extern struct termios	*g_settings;
t_list					**g_list;
int						g_tty;

static t_list	*init_list(const char **argv)
{
	t_list	*list;
	t_list	*elem;
	t_entry	*entry;
	int		i;

	list = NULL;
	elem = NULL;
	i = 1;
	while (argv[i])
	{
		if (!(entry = ft_memalloc(sizeof(t_entry))) || \
			!(elem = ft_lstnew(NULL, 0)))
		{
			ft_perror("ft_select");
			terminate("ft_select", "fatal error, exit");
		}
		entry->content = (char *)argv[i];
		entry->cursor = (!list) ? 1 : 0;
		elem->content = entry;
		ft_lstpushback(&list, elem);
		i++;
	}
	return (list);
}

static void		input(int fd, t_list **list)
{
	long	c;

	redraw_window(fd, *list);
	c = 0;
	while (*list && read(0, &c, READ_BUFF))
	{
		if (c == '\n')
			break ;
		else if (c == KEY_UP || c == KEY_DOWN)
			navigate(*list, c);
		else if (c == ' ')
			mark(*list);
		else if (c == KEY_ESC)
		{
			diselect_all(*list);
			break ;
		}
		else if (c == KEY_BACKSPACE || c == KEY_DEL)
			delete(list);
		redraw_window(fd, *list);
		c = 0;
	}
}

static void		signals_enable(void)
{
	signal(SIGINT, signal_handler);
	signal(SIGABRT, signal_handler);
	signal(SIGSTOP, signal_handler);
	signal(SIGKILL, signal_handler);
	signal(SIGQUIT, signal_handler);
	signal(SIGWINCH, signal_handler);
	signal(SIGTSTP, signal_handler);
	signal(SIGCONT, signal_handler);
}

static void		signals_disable(void)
{
	signal(SIGINT, SIG_IGN);
	signal(SIGABRT, SIG_IGN);
	signal(SIGSTOP, SIG_IGN);
	signal(SIGKILL, SIG_IGN);
	signal(SIGQUIT, SIG_IGN);
	signal(SIGWINCH, SIG_IGN);
	signal(SIGTSTP, SIG_IGN);
	signal(SIGCONT, SIG_IGN);
}

t_list			*ft_select(const char **argv)
{
	t_list	*list;
	int		fd;

	list = init_list(argv);
	g_list = &list;
	fd = open("/dev/tty", O_RDWR);
	g_tty = fd;
	tcsetattr(0, TCSANOW, &g_settings[MOD]);
	ft_putstr_fd(tgetstr("ti", NULL), fd);
	ft_putstr_fd(tgetstr("vi", NULL), fd);
	signals_enable();
	input(fd, &list);
	signals_disable();
	ft_putstr_fd(tgetstr("ve", NULL), fd);
	ft_putstr_fd(tgetstr("te", NULL), fd);
	tcsetattr(0, TCSANOW, &g_settings[DFL]);
	close(fd);
	return (list);
}
