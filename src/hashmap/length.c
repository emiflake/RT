/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   length.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/31 21:51:01 by nmartins       #+#    #+#                */
/*   Updated: 2019/10/31 21:53:44 by nmartins      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ashmap.h"

size_t	ash_length(t_hashmap *map)
{
	t_bucket		*bucket;
	size_t			i;
	size_t			count;

	count = 0;
	i = 0;
	while (i < map->bucket_count)
	{
		bucket = &map->buckets[i];
		count += bucket->node_count;
		i++;
	}
	return (count);
}
