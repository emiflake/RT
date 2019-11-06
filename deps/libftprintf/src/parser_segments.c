/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parser_segments.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/26 16:46:16 by nmartins       #+#    #+#                */
/*   Updated: 2019/07/08 17:02:36 by nloomans      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <assert.h>
#include <stddef.h>
#include "std.h"
#include "token.h"
#include "parser.h"

static const t_str2size			g_map_str2size[] = {
	{ "hh", E_HH },
	{ "h", E_H },
	{ "ll", E_LL },
	{ "l", E_L },
	{ "L", E_LL },
	{ "", E_N },
};

t_size							parse_size(char **stream)
{
	size_t				i;
	size_t				str_len;
	const t_str2size	*elem;

	assert(stream != NULL && *stream != NULL);
	i = 0;
	while (i < sizeof(g_map_str2size) / sizeof(t_str2size))
	{
		elem = &g_map_str2size[i];
		str_len = std_strlen(elem->str);
		if (std_strncmp(*stream, elem->str, str_len) == 0)
		{
			(*stream) += str_len;
			return (elem->size);
		}
		i++;
	}
	assert(0);
}

static const t_char2descriptor	g_map_char2descriptor[] = {
	{ 'd', E_INT },
	{ 'i', E_INT },
	{ 's', E_STR },
	{ 'o', E_OCT },
	{ 'u', E_UNS },
	{ 'p', E_PTR },
	{ 'c', E_CHR },
	{ '%', E_PERCENT },
	{ 'm', E_MEMORY },
	{ 'x', E_HEX },
	{ 'f', E_FLOAT },
};

t_descriptor					parse_conversion_specifier(
	t_flags *flags,
	char **stream,
	int *has_errored)
{
	char	c;
	size_t	i;

	assert(flags != NULL && stream != NULL && *stream != NULL);
	c = **stream;
	(*stream)++;
	if (c == '\0')
	{
		*has_errored = 1;
		return (0);
	}
	if (c >= 'A' && c <= 'Z')
	{
		*flags |= FLAGS_CAPITAL;
		c = std_tolower(c);
	}
	i = 0;
	while (i < sizeof(g_map_char2descriptor) / sizeof(t_char2descriptor))
	{
		if (g_map_char2descriptor[i].c == c)
			return (g_map_char2descriptor[i].descriptor);
		i++;
	}
	*has_errored = 1;
	return (0);
}

int								parse_width(char **stream)
{
	assert(stream != NULL && *stream != NULL);
	return (parse_atoi_wildcard(stream));
}

int								parse_precision(t_flags *flags, char **stream)
{
	assert(flags != NULL && stream != NULL && *stream != NULL);
	if (**stream != '.')
		return (0);
	(*stream)++;
	*flags |= FLAGS_PRECISION;
	return (parse_atoi_wildcard(stream));
}
