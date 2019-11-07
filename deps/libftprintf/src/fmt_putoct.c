/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fmt_putoct.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/22 20:43:22 by nmartins       #+#    #+#                */
/*   Updated: 2019/07/08 17:03:10 by nloomans      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "std.h"
#include "writer.h"
#include "token.h"
#include "fmt.h"
#include <stdarg.h>
#include <stdio.h>

void	do_fmt_putoct(t_writer *writer, t_token *token, t_number number)
{
	char				buf[128];
	size_t				idx;
	size_t				actual_size;

	idx = intern_ntoa(buf, number, 0);
	if (token->flags & FLAGS_HASH && buf[0] != '0' &&
		(!(token->flags & FLAGS_PRECISION) || (size_t)token->precision <= idx))
	{
		token->flags |= FLAGS_PRECISION;
		token->precision = idx + 1;
	}
	actual_size = idx;
	if (token->flags & FLAGS_HASH)
		actual_size++;
	if (token->flags & FLAGS_PRECISION)
		actual_size = std_max(actual_size, token->precision);
	intern_fmt_pad_left(writer, token,
		intern_pad_char(token->flags), actual_size);
	if ((token->flags & FLAGS_PRECISION))
		intern_fmt_pad_auto(writer, '0', token->precision, idx);
	writer_write(writer, buf, idx);
	intern_fmt_pad_right(writer, token,
		intern_pad_char(token->flags), actual_size);
}

void	fmt_putoct(t_writer *writer, t_token *token, va_list vlist)
{
	t_number num;

	intern_pop_wildcards(token, vlist);
	num.value = intern_read_unsigned_int(token->size, vlist);
	num.base = 8U;
	if (num.value == 0
		&& token->flags & FLAGS_PRECISION
		&& token->precision == 0)
	{
		intern_fmt_pad(writer, ' ', token->width -
			!!(token->flags & FLAGS_HASH));
		if (token->flags & FLAGS_HASH)
			writer_write(writer, "0", 1);
	}
	else
		do_fmt_putoct(writer, token, num);
}
