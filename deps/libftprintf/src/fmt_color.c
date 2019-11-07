/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fmt_color.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/25 01:24:49 by nmartins       #+#    #+#                */
/*   Updated: 2019/07/08 16:38:18 by nloomans      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fmt.h"
#include "color.h"
#include "std.h"

static const char	*g_lookup_escape_codes[] = {
	COLOR_RESET,
	COLOR_BLACK,
	COLOR_GRAY,
	COLOR_RED,
	COLOR_GREEN,
	COLOR_YELLOW,
	COLOR_BLUE,
	COLOR_MAGENTA,
	COLOR_CYAN,
	COLOR_WHITE,
	COLOR_UNDERLINE,
	COLOR_REVERSED,
};

static const char	*g_lookup_human_names[] = {
	"reset",
	"black",
	"gray",
	"red",
	"green",
	"yellow",
	"blue",
	"magenta",
	"cyan",
	"white",
	"underline",
	"reversed",
};

const char	*intern_fmt_color_lookup(t_color color)
{
	return (g_lookup_escape_codes[color]);
}

void		intern_fmt_color(t_writer *writer, t_color color)
{
	const char *str = intern_fmt_color_lookup(color);

	writer_write(
		writer,
		(char *)str,
		std_strlen(str));
}

void		fmt_putcolor(t_writer *writer, t_token *token, va_list vlist)
{
	size_t		i;

	i = 0;
	(void)vlist;
	while (i < sizeof(g_lookup_human_names) / sizeof(char*))
	{
		if (!std_memcmp(g_lookup_human_names[i], token->s_value,
			std_strlen(g_lookup_human_names[i])))
			intern_fmt_color(writer, (t_color)i);
		i++;
	}
}
