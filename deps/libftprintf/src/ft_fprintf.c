/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_fprintf.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: nloomans <nloomans@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/07 12:20:27 by nloomans       #+#    #+#                */
/*   Updated: 2019/07/08 16:38:02 by nloomans      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "std.h"
#include <stdarg.h>
#include <stdio.h>
#include "ft_printf.h"
#include "writer.h"

ssize_t		ft_vfprintf(FILE *file, char *fmt, va_list vlist)
{
	t_writer_file_state	*st;
	t_writer			writer;

	st = file;
	std_memset(&writer, 0, sizeof(t_writer));
	writer.state = (void*)st;
	writer.write = &writer_file_write;
	return (ft_vwprintf(&writer, fmt, vlist));
}

ssize_t		ft_fprintf(FILE *file, char *fmt, ...)
{
	va_list		vlist;
	ssize_t		ret;

	va_start(vlist, fmt);
	ret = ft_vfprintf(file, fmt, vlist);
	va_end(vlist);
	return (ret);
}
