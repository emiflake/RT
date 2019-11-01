/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   hashmap.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: emiflake <marvin@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/14 15:11:22 by emiflake       #+#    #+#                */
/*   Updated: 2019/11/01 19:35:26 by nmartins      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>
#include <ft_printf.h>

#include "./ashmap.h"
#include "./ash_common.h"

t_hashmap	*ash_hashmap_new(t_hasher hasher)
{
	return (ash_hashmap_with_size(1024, hasher));
}

t_hashmap	*ash_hashmap_with_size(size_t length, t_hasher hasher)
{
	t_hashmap	*hashmap;
	t_bucket	*buckets;

	hashmap = (t_hashmap*)malloc(sizeof(t_hashmap));
	hashmap->hasher = hasher;
	if (!hashmap)
		return (NULL);
	buckets = (t_bucket*)malloc(sizeof(t_bucket) * length);
	if (!buckets)
	{
		free(hashmap);
		return (NULL);
	}
	ash_buckets_init(buckets, length);
	hashmap->buckets = buckets;
	hashmap->bucket_count = length;
	return (hashmap);
}

t_bucket	*ash_hashmap_get_bucket(t_hashmap *map, char *key)
{
	uint64_t	bucket_idx;

	bucket_idx = map->hasher(key, ash_strlen(key)) % map->bucket_count;
	return (&map->buckets[bucket_idx]);
}

void		*ash_hashmap_insert(t_hashmap *map, char *key, void *value)
{
	t_bucket	*bucket;

	bucket = ash_hashmap_get_bucket(map, key);
	return (ash_bucket_set(bucket, key, value));
}

void		*ash_hashmap_get(t_hashmap *map, char *key)
{
	t_bucket	*bucket;

	bucket = ash_hashmap_get_bucket(map, key);
	return (ash_bucket_get(bucket, key));
}
