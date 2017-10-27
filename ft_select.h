/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbraslav <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/22 17:21:46 by mbraslav          #+#    #+#             */
/*   Updated: 2017/09/22 17:21:46 by mbraslav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SELECT_H
# define FT_SELECT_H

# include <errno.h>
# include <term.h>
# include <stdio.h>
# include <sys/ioctl.h>
# include <unistd.h>
# include <fcntl.h>

# include "libft/libft.h"

# define DFL 0
# define MOD 1
# define TABLEN 8
# define READ_BUFF 8
# define KEY_ESC 0x1b
# define KEY_UP 0x415b1b
# define KEY_DOWN 0x425b1b
# define KEY_RIGHT 0x435b1b
# define KEY_LEFT 0x445b1b
# define KEY_DEL 0x7e335b1b
# define KEY_BACKSPACE 0x7F

typedef struct	s_entry
{
	char		*content;
	char		selected;
	char		cursor;
}				t_entry;

t_list			*ft_select(const char **argv);
void			redraw_window(int fd, t_list *list);

void			navigate(t_list *list, long key);
void			mark(t_list *list);
void			diselect_all(t_list *list);
void			delete(t_list **list);

void			signal_handler(int signal);
void			color(int fd, const char *path);

void			error(const char *error_msg, const char *str);
void			terminate(const char *error_msg, const char *str);
void			ft_perror(const char *error_msg);

#endif
