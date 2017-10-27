/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbraslav <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/15 19:14:09 by mbraslav          #+#    #+#             */
/*   Updated: 2017/10/15 19:14:10 by mbraslav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/stat.h>
#include "ft_select.h"

static void	color2(int fd, int type)
{
	if (type == S_IFDIR)
		ft_putstr_fd("\e[0;34m", fd);
	if (type == S_IFLNK)
		ft_putstr_fd("\e[0;35m", fd);
	else if (type == S_IFSOCK)
		ft_putstr_fd("\e[0;32m", fd);
	else if (type == S_IFIFO)
		ft_putstr_fd("\e[0;33m", fd);
	else if (type == S_IXUSR)
		ft_putstr_fd("\e[0;31m", fd);
	else if (type == S_IFBLK)
		ft_putstr_fd("\e[46;34m", fd);
	else if (type == S_IFCHR)
		ft_putstr_fd("\e[43;34m", fd);
	else if (type == S_IXUSR && type == S_ISUID)
		ft_putstr_fd("\e[31;30m", fd);
	else if (type == S_IXUSR && type == S_ISGID)
		ft_putstr_fd("\e[36;30m", fd);
	else if (type == S_IWOTH && type == S_ISVTX)
		ft_putstr_fd("\e[30;32m", fd);
	else if (type == S_IWOTH && !(type == S_ISVTX))
		ft_putstr_fd("\e[30;33m", fd);
}

void		color(int fd, const char *path)
{
	struct stat	filestat;
	int			type;

	if (lstat(path, &filestat))
		return ;
	type = filestat.st_mode & S_IFMT;
	color2(fd, type);
}
