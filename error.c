/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbraslav <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/09 16:10:11 by mbraslav          #+#    #+#             */
/*   Updated: 2017/08/09 16:10:12 by mbraslav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	error(const char *error_msg, const char *str)
{
	write(2, error_msg, ft_strlen(error_msg));
	write(2, ": ", 2);
	write(2, str, ft_strlen(str));
	write(2, "\n", 1);
}

void	ft_perror(const char *error_msg)
{
	const char	*msg[] = {"Operation not permitted", "No such file or \
directory", "No such process", "Interrupted system call", "Input/output \
error", "Device not configured", "Argument list too long", "Exec format \
error", "Bad file descriptor", "No child processes", "Resource deadlock \
avoided", "Cannot allocate memory", "Permission denied", "Bad address", "Block \
device required", "Device / resource busy", "File exists", "Cross-device \
link", "Operation not supported by device", "Not a directory", "Is a \
directory", "Invalid argument", "Too many open files in system", "Too many \
open files", "Inappropriate ioctl for device", "Text file busy", "File too \
large", "No space left on device", "Illegal seek", "Read-only file system", \
"Too many links", "Broken pipe"};

	write(2, error_msg, ft_strlen(error_msg));
	write(2, ": ", 2);
	if (errno > 0 && errno < 32)
		write(2, msg[errno - 1], ft_strlen(msg[errno - 1]));
	else
		write(2, "Unknown error", 13);
	write(2, "\n", 1);
}

void	terminate(const char *error_msg, const char *str)
{
	error(error_msg, str);
	exit(EXIT_FAILURE);
}
