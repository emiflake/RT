/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fmt_putuns.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/22 17:52:31 by nmartins       #+#    #+#                */
/*   Updated: 2019/07/08 17:03:10 by nloomans      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "std.h"
#include "writer.h"
#include "fmt.h"
#include "token.h"
#include <stdarg.h>
#include <stdio.h>

static t_number				va_arg_unsigned_number(t_size size, va_list vlist)
{
	t_number			number;
	unsigned long long	input;

	input = intern_read_unsigned_int(size, vlist);
	number.sign = 1;
	number.value = input;
	number.base = 10U;
	return (number);
}

void						fmt_putuns(
	t_writer *writer,
	t_token *tok,
	va_list vlist)
{
	char		buf[128];
	t_number	n;
	size_t		idx;
	size_t		actual_size;

	intern_pop_wildcards(tok, vlist);
	n = va_arg_unsigned_number(tok->size, vlist);
	if (n.value == 0
		&& tok->flags & FLAGS_PRECISION
		&& tok->precision == 0)
	{
		intern_fmt_pad(writer, ' ', tok->width);
		return ;
	}
	idx = intern_ntoa(buf, n, 0);
	actual_size = idx;
	if (tok->flags & FLAGS_PRECISION)
		actual_size = std_max(idx, tok->precision);
	intern_fmt_pad_left(writer, tok, intern_pad_char(tok->flags), actual_size);
	if (tok->flags & FLAGS_PRECISION)
		intern_fmt_pad_auto(writer, '0', tok->precision, idx);
	writer_write(writer, buf, idx);
	intern_fmt_pad_right(writer, tok, intern_pad_char(tok->flags), actual_size);
}
