/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fmt_puthex.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/22 19:45:05 by nmartins       #+#    #+#                */
/*   Updated: 2019/07/08 17:03:10 by nloomans      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "std.h"
#include "writer.h"
#include "fmt.h"
#include "token.h"
#include <stdarg.h>
#include <stdio.h>

int				intern_hex_size(long long n)
{
	int	count;

	count = 1;
	if (n < 0)
	{
		count++;
		n = -n;
	}
	while (n / 16)
	{
		count++;
		n /= 16;
	}
	return (count);
}

void			intern_fmt_puthex(
	t_writer *writer,
	unsigned long long value,
	int caps)
{
	char	c;

	if (value >= 16)
		intern_fmt_puthex(writer, value / 16, caps);
	c = intern_to_hex(value % 16, caps);
	writer_write(writer, &c, 1);
}

static int		prefix_size(t_number *num, t_flags flags)
{
	if (flags & FLAGS_HASH && num->value != 0)
		return (2);
	else
		return (0);
}

static void		fmt_do_puthex(
	t_writer *writer,
	t_token *token,
	t_number number)
{
	unsigned long long	own_hex_size;
	char				buf[128];
	size_t				idx;

	idx = intern_ntoa(buf, number, token->flags & FLAGS_CAPITAL);
	own_hex_size = prefix_size(&number, token->flags);
	own_hex_size = token->flags & FLAGS_PRECISION
		? (size_t)std_max(token->precision + own_hex_size, own_hex_size + idx)
		: own_hex_size + idx;
	if (!(token->flags & FLAGS_ZEROPAD))
		intern_fmt_pad_left(writer, token, ' ', own_hex_size);
	if ((token->flags & FLAGS_HASH) && number.value != 0)
		writer_write(writer,
			token->flags & FLAGS_CAPITAL ? "0X" : "0x", 2);
	if (token->flags & FLAGS_ZEROPAD)
		intern_fmt_pad(writer, '0', token->width - (int)own_hex_size);
	if (token->flags & FLAGS_PRECISION && idx < (size_t)token->precision)
		intern_fmt_pad(writer, '0', token->precision - (int)idx);
	writer_write(writer, buf, idx);
	if (!(token->flags & FLAGS_ZEROPAD))
		intern_fmt_pad_right(writer, token, ' ', (int)own_hex_size);
}

void			fmt_puthex(t_writer *writer, t_token *token, va_list vlist)
{
	unsigned long long	n;
	t_number			number;

	intern_pop_wildcards(token, vlist);
	n = intern_read_unsigned_int(token->size, vlist);
	number.value = n;
	number.base = 16U;
	if (number.value == 0
		&& token->flags & FLAGS_PRECISION
		&& token->precision == 0)
		intern_fmt_pad(writer, ' ', token->width);
	else
		fmt_do_puthex(writer, token, number);
}
