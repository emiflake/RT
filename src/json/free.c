/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   free.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/01 14:18:57 by nmartins       #+#    #+#                */
/*   Updated: 2019/11/01 19:35:38 by nmartins      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <ft_printf.h>

#include "json.h"

static void		node_free(t_json_list_node *node)
{
	if (!node)
		return ;
	node_free(node->next);
	json_free(node->value);
	free(node);
}

static void		map_clean(void *data)
{
	const t_bucket_node	*node = data;

	free(node->key);
	json_free(node->value);
}

static void		dict_free(t_hashmap *map)
{
	ash_hashmap_clean(map, map_clean);
}

void			json_free(t_json_value *val)
{
	if (val->type == JSON_STRING)
		free(val->value.as_string);
	else if (val->type == JSON_LIST)
		node_free(val->value.as_list.root);
	else if (val->type == JSON_DICT)
		dict_free(val->value.as_dict.hashmap);
	free(val);
}
