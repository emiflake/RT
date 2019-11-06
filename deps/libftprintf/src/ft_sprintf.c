/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_sprintf.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/03 15:44:26 by nmartins       #+#    #+#                */
/*   Updated: 2019/07/08 16:38:02 by nloomans      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "std.h"
#include "ft_printf.h"
#include "writer.h"

ssize_t		ft_vsnprintf(char *dest, ssize_t capacity, char *fmt, va_list vlist)
{
	t_writer_string_state	st;
	t_writer				writer;
	ssize_t					ret;

	st.maximum = capacity > 0 ? capacity - 1 : capacity;
	st.str_ptr = dest;
	st.actually_written = 0;
	std_memset(&writer, 0, sizeof(t_writer));
	writer.state = (void*)&st;
	writer.write = &writer_string_write;
	ret = ft_vwprintf(&writer, fmt, vlist);
	if (capacity != 0)
		dest[st.actually_written] = '\0';
	return (ret);
}

ssize_t		ft_vsprintf(char *dest, char *fmt, va_list vlist)
{
	return (ft_vsnprintf(dest, -1, fmt, vlist));
}

ssize_t		ft_snprintf(char *dest, ssize_t capacity, char *fmt, ...)
{
	va_list		vlist;
	ssize_t		ret;

	va_start(vlist, fmt);
	ret = ft_vsnprintf(dest, capacity, fmt, vlist);
	va_end(vlist);
	return (ret);
}

ssize_t		ft_sprintf(char *dest, char *fmt, ...)
{
	va_list		vlist;
	ssize_t		ret;

	va_start(vlist, fmt);
	ret = ft_vsnprintf(dest, -1, fmt, vlist);
	va_end(vlist);
	return (ret);
}
