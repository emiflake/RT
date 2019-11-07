/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fmt_putptr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/22 19:33:43 by nmartins       #+#    #+#                */
/*   Updated: 2019/07/08 17:03:10 by nloomans      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "std.h"
#include <stdarg.h>
#include "fmt.h"
#include "writer.h"
#include "token.h"

void			fmt_putptr(t_writer *writer, t_token *token, va_list vlist)
{
	unsigned long long	actual_size;
	unsigned long long	n;
	t_number			number;
	char				buf[128];
	size_t				idx;

	intern_pop_wildcards(token, vlist);
	n = (unsigned long long)va_arg(vlist, void *);
	number.value = n;
	number.base = 16U;
	idx = intern_ntoa(buf, number, token->flags & FLAGS_CAPITAL);
	actual_size = 2;
	actual_size += idx;
	actual_size = token->flags & FLAGS_PRECISION
		? (size_t)std_max(token->precision, actual_size)
		: actual_size;
	intern_fmt_pad_left(writer, token, ' ', actual_size);
	writer_write(writer, token->flags & FLAGS_CAPITAL ? "0X" : "0x", 2);
	if (token->flags & FLAGS_PRECISION && idx < (size_t)token->precision)
		intern_fmt_pad(writer, '0', token->precision - idx);
	writer_write(writer, buf, idx);
	intern_fmt_pad_right(writer, token, ' ', actual_size);
}
