/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fmt_padding.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/24 17:27:57 by nmartins       #+#    #+#                */
/*   Updated: 2019/07/08 16:40:56 by nloomans      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fmt.h"
#include "token.h"
#include "std.h"
#include <stdlib.h>

void	intern_fmt_pad(t_writer *writer, char c, int amt)
{
	char	*str;

	if (amt <= 0)
		return ;
	str = (char*)malloc(amt);
	if (!str)
	{
		writer->failed = 1;
		return ;
	}
	std_memset(str, c, amt);
	writer_write(writer, str, amt);
	free(str);
}

void	intern_fmt_pad_auto(
	t_writer *writer,
	char c,
	int pad_amount,
	int length)
{
	if (pad_amount > length)
		intern_fmt_pad(writer, c, pad_amount - length);
}

void	intern_fmt_pad_left(
	t_writer *writer,
	t_token *token,
	char c,
	int length)
{
	if ((token->flags & FLAGS_LEFTALIGN) == 0)
		intern_fmt_pad_auto(writer, c, token->width, length);
}

void	intern_fmt_pad_right(
	t_writer *writer,
	t_token *token,
	char c,
	int length)
{
	if (token->flags & FLAGS_LEFTALIGN)
		intern_fmt_pad_auto(writer, c, token->width, length);
}
