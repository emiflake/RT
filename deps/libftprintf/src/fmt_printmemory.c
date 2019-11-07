/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fmt_printmemory.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/23 16:39:30 by nmartins       #+#    #+#                */
/*   Updated: 2019/07/08 16:59:25 by nloomans      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fmt.h"
#include "color.h"

#include "std.h"

static void		intern_fmt_puthexchar(
	t_writer *writer,
	unsigned char c,
	t_flags flags)
{
	const char b = intern_to_hex(c % 16, flags & FLAGS_CAPITAL);
	const char a = intern_to_hex(c / 16, flags & FLAGS_CAPITAL);

	writer_write(writer, (char*)&a, 1);
	writer_write(writer, (char*)&b, 1);
}

static void		intern_fmt_putmemchars(
	t_writer *writer,
	unsigned char *bytes,
	size_t offset,
	size_t len)
{
	const size_t	start = offset;

	while (offset < len && offset - start < 16)
	{
		if (std_isprint(bytes[offset]))
		{
			intern_fmt_color(writer, E_WHITE);
			writer_write(writer, (char*)&bytes[offset], 1);
		}
		else
		{
			intern_fmt_color(writer, E_GRAY);
			writer_write(writer, ".", 1);
		}
		offset++;
	}
}

static void		print_row(
	t_writer *writer,
	t_flags flags,
	unsigned char *bytes,
	size_t length)
{
	size_t		index;

	index = 0;
	while (index < 16)
	{
		if (index > 0 && index % 2 == 0)
			writer_write(writer, " ", 1);
		if (index < length)
		{
			if (std_isprint(bytes[index]))
				intern_fmt_color(writer, E_CYAN);
			else if (bytes[index])
				intern_fmt_color(writer, E_MAGENTA);
			else
				intern_fmt_color(writer, E_GRAY);
			intern_fmt_puthexchar(writer, bytes[index], flags);
		}
		else
			writer_write(writer, "  ", 2);
		index++;
	}
}

void			intern_fmt_printmemory(
	t_writer *writer,
	unsigned char *bytes,
	size_t len,
	t_flags flags)
{
	size_t			row;

	row = 0;
	if (bytes == NULL)
	{
		writer_write(writer, "(null-pointer)\n", 15);
	}
	while (row < ((len - 1) / 16) + 1)
	{
		if (flags & FLAGS_HASH)
		{
			intern_fmt_color(writer, E_GREEN);
			intern_fmt_pad_auto(writer, '0', 8, intern_hex_size(row * 16));
			intern_fmt_puthex(writer, row * 16, flags & FLAGS_CAPITAL);
			writer_write(writer, ": ", 2);
		}
		print_row(writer, flags, bytes + (row * 16), len - (row * 16));
		writer_write(writer, " ", 1);
		intern_fmt_color(writer, E_RED);
		intern_fmt_putmemchars(writer, bytes, row * 16, len);
		writer_write(writer, "\n", 1);
		row++;
	}
}

void			fmt_printmemory(t_writer *writer, t_token *token, va_list vlist)
{
	void	*addr;
	size_t	len;

	addr = va_arg(vlist, void*);
	len = va_arg(vlist, size_t);
	intern_fmt_printmemory(writer, (unsigned char *)addr, len, token->flags);
}
