/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   runner.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/22 15:17:29 by nmartins       #+#    #+#                */
/*   Updated: 2019/07/08 15:51:14 by nloomans      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "token.h"
#include "writer.h"
#include "fmt.h"
#include "std.h"
#include <stdio.h>

void			run_token(t_writer *writer, va_list vlist, t_token *token)
{
	const t_formatter	fmts[] = {
		fmt_putstrlit,
		fmt_putpercent,
		fmt_putnbr,
		fmt_putstr,
		fmt_putuns,
		fmt_putptr,
		fmt_puthex,
		fmt_putchr,
		fmt_putoct,
		fmt_putflt,
		fmt_printmemory,
		fmt_putcolor,
	};

	fmts[token->type](writer, token, vlist);
}
