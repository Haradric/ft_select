/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbraslav <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/22 17:22:03 by mbraslav          #+#    #+#             */
/*   Updated: 2017/09/22 17:22:04 by mbraslav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

extern struct termios	*g_settings;
extern t_list			**g_list;
extern int				g_tty;

static void	sigint_handler(void)
{
	ft_putstr_fd(tgetstr("ve", NULL), g_tty);
	ft_putstr_fd(tgetstr("te", NULL), g_tty);
	tcsetattr(0, TCSANOW, &g_settings[DFL]);
	exit(EXIT_SUCCESS);
}

static void	sigwinch_handler(void)
{
	redraw_window(g_tty, *g_list);
}

static void	sigtstp_handler(void)
{
	ft_putstr_fd(tgetstr("ve", NULL), g_tty);
	ft_putstr_fd(tgetstr("te", NULL), g_tty);
	tcsetattr(0, TCSANOW, &g_settings[DFL]);
	signal(SIGTSTP, SIG_DFL);
	ioctl(STDERR_FILENO, TIOCSTI, "\x1A");
}

static void	sigcont_handler(void)
{
	tcsetattr(0, TCSANOW, &g_settings[MOD]);
	ft_putstr_fd(tgetstr("ti", NULL), g_tty);
	ft_putstr_fd(tgetstr("vi", NULL), g_tty);
	redraw_window(g_tty, *g_list);
	signal(SIGINT, signal_handler);
	signal(SIGWINCH, signal_handler);
	signal(SIGTSTP, signal_handler);
	signal(SIGCONT, signal_handler);
}

void		signal_handler(int signal)
{
	if (signal == SIGINT || signal == SIGABRT || signal == SIGSTOP || \
		signal == SIGKILL || signal == SIGQUIT)
		sigint_handler();
	else if (signal == SIGWINCH)
		sigwinch_handler();
	else if (signal == SIGTSTP)
		sigtstp_handler();
	else if (signal == SIGCONT)
		sigcont_handler();
}
