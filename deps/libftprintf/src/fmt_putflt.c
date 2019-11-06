/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fmt_putflt.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/23 00:44:24 by nmartins       #+#    #+#                */
/*   Updated: 2019/07/08 15:51:14 by nloomans      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "std.h"
#include <stdarg.h>
#include <stdio.h>
#include <assert.h>
#include "writer.h"
#include "token.h"
#include "fmt.h"

/*
** Calculate the size a float will be (excluding padding). This ashumes that
** precision has been set to the default if it was unset.
**
** If n < 0 we count 1 extra to account for the `-'.
** If precision > 0 we count 1 extra to account for the `.'.
*/

static size_t	float_size(t_token *token, size_t before_dot, long double n)
{
	size_t	size;

	size = 0;
	if (n < 0 || token->flags & FLAGS_PLUS || token->flags & FLAGS_SPACE)
		size++;
	size += before_dot;
	if (token->precision > 0)
		size++;
	size += token->precision;
	return (size);
}

static void		mk_float_number(t_number *num, long double *n, int precision)
{
	int i;

	num->base = 10U;
	num->sign = (*n >= 0 ? 1 : -1);
	if (*n == 0 && 1.0 / *n == 1.0 / -0.0)
		num->sign = -1;
	if (num->sign == -1)
		*n *= -1;
	i = 0;
	while (i < precision)
	{
		*n *= 10;
		i++;
	}
	*n = (long double)(long long)(*n + 0.5);
	i = 0;
	while (i < precision)
	{
		*n /= 10;
		i++;
	}
	num->value = (long long)*n;
}

static void		print_real_float(
	t_writer *writer,
	t_token *token,
	long double n)
{
	char		buf[128];
	t_number	num;
	double		fract;
	size_t		idx;
	size_t		size;

	mk_float_number(&num, &n, token->precision);
	fract = n - (long long)n;
	idx = intern_ntoa(buf, num, 0);
	size = float_size(token, idx, n);
	intern_number_prefix(writer, token, num, size);
	writer_write(writer, buf, idx);
	if (token->precision > 0)
		writer_write(writer, ".", 1);
	while (token->precision > 0)
	{
		fract *= 10;
		num.value = (unsigned long long)fract;
		fract -= num.value;
		idx = intern_ntoa(buf, num, 0);
		writer_write(writer, buf, idx);
		token->precision--;
	}
	intern_fmt_pad_right(writer, token, intern_pad_char(token->flags), size);
}

static void		print_fake_float(
	t_writer *writer,
	t_token *token,
	long double n)
{
	if (token->flags & FLAGS_CAPITAL)
	{
		if (n != n)
			writer_write(writer, "NAN", 3);
		else if (n == 1.0 / 0.0)
			writer_write(writer, "INF", 3);
		else if (n == -1.0 / 0.0)
			writer_write(writer, "-INF", 4);
		else
			assert(0);
	}
	else
	{
		if (n != n)
			writer_write(writer, "nan", 3);
		else if (n == 1.0 / 0.0)
			writer_write(writer, "inf", 3);
		else if (n == -1.0 / 0.0)
			writer_write(writer, "-inf", 4);
		else
			assert(0);
	}
}

void			fmt_putflt(t_writer *writer, t_token *token, va_list vlist)
{
	long double		n;

	intern_pop_wildcards(token, vlist);
	if (!(token->flags & FLAGS_PRECISION))
		token->precision = 6;
	n = intern_read_float(token->size, vlist);
	if (n != n || n == 1.0 / 0.0 || n == -1.0 / 0.0)
		print_fake_float(writer, token, n);
	else
		print_real_float(writer, token, n);
}
