/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   clean.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: emiflake <marvin@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/14 18:53:08 by emiflake       #+#    #+#                */
/*   Updated: 2019/10/31 18:57:04 by nmartins      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "./ashmap.h"
#include "./ash_common.h"

static void	ash_hashmap_clean_buckets(t_bucket *bucket, void (*clean_f)(void*))
{
	t_bucket_node	*curr_node;
	t_bucket_node	*next_node;

	if (bucket->node_count == 0)
		return ;
	curr_node = bucket->nodes;
	next_node = curr_node->next;
	while (curr_node)
	{
		next_node = curr_node->next;
		if (curr_node->value)
			clean_f(curr_node->value);
		free(curr_node);
		curr_node = next_node;
	}
}

void		ash_hashmap_clean(
	t_hashmap *map,
	void (*clean_f)(void*))
{
	t_bucket	*bucket_walker;
	size_t		i;

	i = 0;
	while (i < map->bucket_count)
	{
		bucket_walker = &map->buckets[i];
		ash_hashmap_clean_buckets(bucket_walker, clean_f);
		i++;
	}
	free(map->buckets);
	free(map);
}
