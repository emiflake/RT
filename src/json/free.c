/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   free.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/01 14:18:57 by nmartins       #+#    #+#                */
/*   Updated: 2019/11/01 15:00:44 by nmartins      ########   odam.nl         */
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

	ft_printf("Cleaning %s\n", node->key);

	free(node->key);
	json_free(node->value);
}

static void		dict_free(t_hashmap *map)
{
	ft_printf("Freeing DICT\n");
	for (size_t i = 0; i < map->bucket_count; i++)
		ft_printf("%llu\n", map->buckets[i].node_count);
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
