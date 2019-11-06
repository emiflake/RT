/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fmt_putpercent.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/24 16:36:15 by nmartins       #+#    #+#                */
/*   Updated: 2019/07/08 17:03:10 by nloomans      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fmt.h"
#include "std.h"

void			fmt_putpercent(t_writer *writer, t_token *token, va_list vlist)
{
	(void)vlist;
	if ((token->flags & FLAGS_LEFTALIGN) == 0)
		intern_fmt_pad(writer, ' ', std_max(0, token->width - 1));
	writer_write(writer, "%", 1);
	if (token->flags & FLAGS_LEFTALIGN)
		intern_fmt_pad(writer, ' ', std_max(0, token->width - 1));
}
