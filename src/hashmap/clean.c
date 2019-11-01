/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   clean.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: emiflake <marvin@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/14 18:53:08 by emiflake       #+#    #+#                */
/*   Updated: 2019/11/01 14:59:00 by nmartins      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

#include "./ashmap.h"
#include "./ash_common.h"

static void ash_hashmap_clean_node(t_bucket_node *node, void (*clean_f)(void*))
{
	if (!node)
		return ;
	ash_hashmap_clean_node(node->next, clean_f);
	clean_f(node);
	free(node);
}

static void	ash_hashmap_clean_buckets(t_bucket *bucket, void (*clean_f)(void*))
{
	ash_hashmap_clean_node(bucket->nodes, clean_f);
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
