/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   dict_debug.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/31 21:49:30 by nmartins       #+#    #+#                */
/*   Updated: 2019/11/20 17:31:24 by nmartins      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "json.h"
#include <stdbool.h>
#include <ft_printf.h>
#include <assert.h>

static void		do_kvp_debug(const t_bucket_node *node, size_t indentation)
{
	assert(node != NULL);
	ft_printf("%*s\"%s\": ", indentation, "", node->key);
	if (((t_json_value*)node->value)->type == JSON_NUMBER
		|| ((t_json_value*)node->value)->type == JSON_STRING)
		do_json_debug(node->value, 0);
	else
	{
		ft_printf("\n");
		do_json_debug(node->value, indentation);
	}
}

void			do_debug_bucket(
	const t_bucket *bucket, bool *was_first, size_t indentation)
{
	size_t			j;
	t_bucket_node	*node;

	node = bucket->nodes;
	j = 0;
	while (j < bucket->node_count)
	{
		if (*was_first)
			*was_first = false;
		else
		{
			ft_printf(",");
			ft_printf("\n");
		}
		do_kvp_debug(node, indentation + 4);
		node = node->next;
		j++;
	}
}

void			do_dict_debug(const t_json_dict *dict, size_t indentation)
{
	t_bucket		*bucket;
	size_t			i;
	bool			was_first;

	if (ash_length(dict->hashmap) == 0)
	{
		ft_printf("%*s{}", indentation, "");
		return ;
	}
	was_first = true;
	ft_printf("%*s{\n", indentation, "");
	i = 0;
	while (i < dict->hashmap->bucket_count)
	{
		bucket = &dict->hashmap->buckets[i];
		do_debug_bucket(bucket, &was_first, indentation);
		i++;
	}
	ft_printf("\n%*s}", indentation, "");
}
