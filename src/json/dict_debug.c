/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   dict_debug.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/31 21:49:30 by nmartins       #+#    #+#                */
/*   Updated: 2019/10/31 21:53:08 by nmartins      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "json.h"
#include <stdbool.h>
#include <ft_printf.h>

static void		do_kvp_debug(const t_bucket_node *node, size_t indentation)
{
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

void			do_dict_debug(const t_json_dict *dict, size_t indentation)
{
	t_bucket		*bucket;
	t_bucket_node	*node;
	size_t			i;
	size_t			j;
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
		j = 0;
		node = bucket->nodes;
		while (j < bucket->node_count)
		{
			if (was_first)
				was_first = false;
			else
			{
				ft_printf(",");
				ft_printf("\n");
			}
			do_kvp_debug(node, indentation + 4);
			node = node->next;
			j++;
		}
		i++;
	}
	ft_printf("\n%*s}", indentation, "");
}
