/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parser.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: nloomans <nloomans@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/03 16:12:16 by nloomans       #+#    #+#                */
/*   Updated: 2019/07/08 16:38:02 by nloomans      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <assert.h>
#include <stddef.h>
#include "std.h"
#include "token.h"
#include "parser.h"

static int			parse_color_specification(t_token *dest, char **stream)
{
	assert(dest != NULL && stream != NULL && *stream != NULL);
	assert(is_color_specification(*stream));
	(*stream) += 2;
	dest->type = E_COLOR;
	dest->s_value = *stream;
	while (**stream != '}' && **stream != '\0')
		(*stream)++;
	dest->s_length = *stream - dest->s_value;
	if (**stream == '\0')
		return (-1);
	else
		(*stream)++;
	return (**stream != '\0');
}

static int			parse_flags(char **stream, int *has_errored)
{
	t_flags		flags;

	assert(stream != NULL && *stream != NULL);
	flags = 0;
	while (std_strchr("# 0+-", **stream))
	{
		if (**stream == '#')
			flags |= FLAGS_HASH;
		else if (**stream == ' ')
			flags |= FLAGS_SPACE;
		else if (**stream == '0')
			flags |= FLAGS_ZEROPAD;
		else if (**stream == '+')
			flags |= FLAGS_PLUS;
		else if (**stream == '-')
			flags |= FLAGS_LEFTALIGN;
		else if (**stream == '\0')
			*has_errored = 1;
		else
			assert(0);
		(*stream)++;
	}
	return (flags);
}

static int			parse_conversion_specification(t_token *dest, char **stream)
{
	int		has_errored;

	assert(dest != NULL && stream != NULL && *stream != NULL);
	assert(is_conversion_specification(*stream));
	has_errored = 0;
	(*stream)++;
	dest->flags = parse_flags(stream, &has_errored);
	if (has_errored)
		return (-1);
	dest->width = parse_width(stream);
	dest->precision = parse_precision(&dest->flags, stream);
	dest->size = parse_size(stream);
	dest->type = parse_conversion_specifier(&dest->flags, stream, &has_errored);
	if (has_errored)
		return (-1);
	truncate_flags(dest);
	return (**stream != '\0');
}

static int			parse_string_literal(t_token *dest, char **stream)
{
	assert(dest != NULL && stream != NULL && *stream != NULL);
	assert(!is_conversion_specification(*stream));
	dest->type = E_TXT;
	dest->s_value = *stream;
	while (!is_conversion_specification(*stream) && **stream != '\0')
		(*stream)++;
	dest->s_length = *stream - dest->s_value;
	return (**stream != '\0');
}

int					parse_token(t_token *dest, char **stream)
{
	assert(dest != NULL && stream != NULL && *stream != NULL);
	std_memset(dest, '\0', sizeof(t_token));
	if (is_color_specification(*stream))
		return (parse_color_specification(dest, stream));
	else if (is_conversion_specification(*stream))
		return (parse_conversion_specification(dest, stream));
	else
		return (parse_string_literal(dest, stream));
}
