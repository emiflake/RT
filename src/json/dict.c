/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   dict.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/31 20:31:37 by nmartins       #+#    #+#                */
/*   Updated: 2019/11/12 17:24:00 by nmartins      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "json.h"
#include <stdlib.h>
#include <ft_printf.h>

static t_json_value	*mk_dict(t_hashmap *dict)
{
	t_json_value	*val;

	val = (t_json_value*)malloc(sizeof(t_json_value));
	val->type = JSON_DICT;
	val->value.as_dict.hashmap = dict;
	return (val);
}

size_t				parse_and_insert_kvp(t_hashmap *dict, const char **str)
{
	t_json_value	*key;
	t_json_value	*value;

	skip_whitespace(str);
	key = do_parse_string(str);
	if (!key || key->type != JSON_STRING)
		return (1);
	skip_whitespace(str);
	if (**str != ':')
		return (1);
	(*str)++;
	skip_whitespace(str);
	value = do_parse_json(str);
	ash_hashmap_insert(dict, key->value.as_string, value);
	free(key);
	skip_whitespace(str);
	return (0);
}

t_json_value		*do_parse_dict(const char **str)
{
	t_hashmap		*dict;
	const char		*walker;

	walker = *str;
	skip_whitespace(&walker);
	if (*walker != '{')
		return (NULL);
	dict = ash_hashmap_with_size(8, ash_hash);
	walker++;
	parse_and_insert_kvp(dict, &walker);
	while (*walker == ',')
	{
		walker++;
		parse_and_insert_kvp(dict, &walker);
	}
	skip_whitespace(&walker);
	if (*walker != '}')
		return (NULL);
	*str = &walker[1];
	return (mk_dict(dict));
}
