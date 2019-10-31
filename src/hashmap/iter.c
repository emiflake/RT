/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   iter.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: emiflake <marvin@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/14 18:27:24 by emiflake       #+#    #+#                */
/*   Updated: 2019/10/31 18:57:29 by nmartins      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "./ashmap.h"
#include "./ash_common.h"

void	ash_hashmap_foreach_share(t_hashmap *map,
	void (*iter_f)(size_t, size_t, t_bucket_node*, void *), void *shared)
{
	t_bucket_node	*bucket_node_walker;
	t_bucket		*bucket_walker;
	size_t			i;
	size_t			j;

	i = 0;
	while (i < map->bucket_count)
	{
		j = 0;
		bucket_walker = &map->buckets[i];
		bucket_node_walker = bucket_walker->nodes;
		while (bucket_node_walker)
		{
			iter_f(i, j, bucket_node_walker, shared);
			bucket_node_walker = bucket_node_walker->next;
			j++;
		}
		i += 1;
	}
}

void	ash_hashmap_foreach_enum(t_hashmap *map,
	void (*iter_f)(size_t, size_t, t_bucket_node*))
{
	t_bucket_node	*bucket_node_walker;
	t_bucket		*bucket_walker;
	size_t			i;
	size_t			j;

	i = 0;
	while (i < map->bucket_count)
	{
		j = 0;
		bucket_walker = &map->buckets[i];
		bucket_node_walker = bucket_walker->nodes;
		while (bucket_node_walker)
		{
			iter_f(i, j, bucket_node_walker);
			bucket_node_walker = bucket_node_walker->next;
			j++;
		}
		i += 1;
	}
}

void	ash_hashmap_foreach(t_hashmap *map,
	void (*iter_f)(t_bucket_node*))
{
	t_bucket_node	*bucket_node_walker;
	t_bucket		*bucket_walker;
	size_t			i;

	i = 0;
	while (i < map->bucket_count)
	{
		bucket_walker = &map->buckets[i];
		bucket_node_walker = bucket_walker->nodes;
		while (bucket_node_walker)
		{
			iter_f(bucket_node_walker);
			bucket_node_walker = bucket_node_walker->next;
		}
		i++;
	}
}
