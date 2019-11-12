/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   comb.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/12 16:46:25 by nmartins       #+#    #+#                */
/*   Updated: 2019/11/12 17:23:13 by nmartins      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "algebra/vector/vector.h"
#include "json.h"

t_json_value	*dict_get(const t_json_value *val, char *key)
{
	t_hashmap	*map;

	if (val->type != JSON_DICT)
		return (NULL);
	map = val->value.as_dict.hashmap;
	return ((t_json_value*)ash_hashmap_get(map, key));
}

double			dict_def_double(const t_json_value *val, char *key, double def)
{
	const t_json_value *obj = dict_get(val, key);

	if (!obj || obj->type != JSON_NUMBER)
		return (def);
	else
		return (obj->value.as_number);
}

char			*dict_def_string(const t_json_value *val, char *key, char *str)
{
	const t_json_value *obj = dict_get(val, key);

	if (!obj || obj->type != JSON_STRING)
		return (str);
	else
		return (obj->value.as_string);
}
