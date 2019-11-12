/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   vec_def.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/12 16:59:07 by nmartins       #+#    #+#                */
/*   Updated: 2019/11/12 18:49:01 by nmartins      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "json.h"
#include "algebra/vector/vector.h"

void	list_def_parse_vec(
	const t_json_list_node *root, const t_vec def, t_vec *out)
{
	if (root->value->type == JSON_NUMBER
	&& root->next->value->type == JSON_NUMBER
	&& root->next->next->value->type == JSON_NUMBER)
	{
		*out = (t_vec){
			.z = root->value->value.as_number,
			.y = root->next->value->value.as_number,
			.x = root->next->next->value->value.as_number,
		};
	}
	else
	{
		*out = def;
	}
}

void	dict_def_vec(
	const t_json_value *val, char *key, const t_vec def, t_vec *out)
{
	const t_json_value	*obj = dict_get(val, key);
	t_json_list_node	*root;

	if (!obj || obj->type != JSON_LIST)
		*out = def;
	else
	{
		root = obj->value.as_list.root;
		if (root && root->next && root->next->next && !root->next->next->next)
			list_def_parse_vec(root, def, out);
		else
			*out = def;
	}
}
