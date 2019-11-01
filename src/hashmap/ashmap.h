/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ashmap.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: emiflake <marvin@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/14 15:42:32 by emiflake       #+#    #+#                */
/*   Updated: 2019/11/01 14:14:33 by nmartins      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

/*
**     ___         __    __  ___
**    /   |  _____/ /_  /  |/  /___ _____
**   / /| | / ___/ __ \/ /|_/ / __ `/ __ \
**  / ___ |(__  ) / / / /  / / /_/ / /_/ /
** /_/  |_/____/_/ /_/_/  /_/\__,_/ .___/
**                               /_/
**       - A C89 Hashmap implementation
*/

#ifndef ASHMAP_H
# define ASHMAP_H

# include <stdint.h>
# include <stddef.h>

typedef uint64_t	(*t_hasher)(const void *buf, size_t buf_len);

typedef struct		s_bucket_node
{
	char					*key;
	void					*value;

	struct s_bucket_node	*next;
}					t_bucket_node;

typedef struct		s_bucket
{
	t_bucket_node	*nodes;
	size_t			node_count;
}					t_bucket;

typedef struct		s_hashmap
{
	t_hasher	hasher;
	t_bucket	*buckets;
	size_t		bucket_count;
}					t_hashmap;

t_hashmap			*ash_hashmap_new(t_hasher hasher);
t_hashmap			*ash_hashmap_with_size(size_t length, t_hasher hasher);
t_bucket			*ash_hashmap_get_bucket(t_hashmap *map, char *key);
void				*ash_bucket_get(t_bucket *bucket, char *key);
void				*ash_bucket_set(t_bucket *bucket, char *key, void *value);
void				ash_buckets_init(t_bucket *buckets, size_t length);
void				*ash_hashmap_insert(t_hashmap *map, char *key, void *value);
void				*ash_hashmap_get(t_hashmap *map, char *key);
size_t				ash_length(t_hashmap *map);

uint64_t			ash_hash(const void *bytes, size_t len);
uint64_t			ash_hash_fnv_64(const void *bytes, size_t len);
void				ash_hashmap_shared(
	t_hashmap *map,
	void(*iter_f)(size_t, size_t, t_bucket_node*, void *),
	void *shared);

void				ash_hashmap_foreach_enum(t_hashmap *map,
	void(*iter_f)(size_t, size_t, t_bucket_node*));

void				ash_hashmap_foreach(t_hashmap *map,
	void(*iter_f)(t_bucket_node*));

void				ash_hashmap_clean(
	t_hashmap *map,
	void(*clean_f)(void*));

#endif
