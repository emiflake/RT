/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fmt_putnbr.c                                       :+:    :+:            */
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

unsigned long long			intern_abs(long long source)
{
	if (source >= 0)
		return ((unsigned long long)source);
	else
		return (-((unsigned long long)source));
}

void						intern_read_number(
	t_number *number,
	t_size size,
	unsigned char base,
	va_list vlist)
{
	long long	value;

	value = intern_read_signed_int(size, vlist);
	number->sign = value >= 0 ? 1 : -1;
	number->value = intern_abs(value);
	number->base = base;
}

static size_t				calculate_actual_size(
	const t_token *tok,
	size_t number_width,
	const t_number *number)
{
	size_t		actual_size;

	if (tok->flags & FLAGS_PRECISION)
		actual_size = std_max(number_width, tok->precision);
	else
		actual_size = number_width;
	if (number->sign == -1 || tok->flags & (FLAGS_PLUS | FLAGS_SPACE))
		actual_size++;
	return (actual_size);
}

void						fmt_putnbr(
	t_writer *writer,
	t_token *tok,
	va_list vlist)
{
	char		buf[128];
	t_number	n;
	size_t		idx;
	size_t		size;

	intern_pop_wildcards(tok, vlist);
	intern_read_number(&n, tok->size, 10U, vlist);
	if (n.value == 0
		&& tok->flags & FLAGS_PRECISION
		&& tok->precision == 0)
	{
		intern_fmt_pad(writer, ' ', tok->width);
		return ;
	}
	idx = intern_ntoa(buf, n, 0);
	size = calculate_actual_size(tok, idx, &n);
	intern_number_prefix(writer, tok, n, size);
	if (tok->flags & FLAGS_PRECISION)
		intern_fmt_pad_auto(writer, '0', tok->precision, idx);
	writer_write(writer, buf, idx);
	intern_fmt_pad_right(writer, tok, intern_pad_char(tok->flags), size);
}
