/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   bucket.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: emiflake <marvin@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/14 15:53:21 by emiflake       #+#    #+#                */
/*   Updated: 2019/10/31 21:16:07 by nmartins      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

#include "./ashmap.h"
#include "./ash_common.h"

void			*ash_bucket_get(t_bucket *bucket, char *key)
{
	t_bucket_node	*walker;

	if (bucket->node_count == 0)
		return (NULL);
	walker = bucket->nodes;
	while (walker)
	{
		if (ash_strcmp(walker->key, key) == 0)
		{
			return (walker->value);
		}
		walker = walker->next;
	}
	return (NULL);
}

t_bucket_node	*ash_create_node(char *key, void *value)
{
	t_bucket_node	*new_node;

	new_node = (t_bucket_node*)malloc(sizeof(t_bucket_node));
	new_node->next = NULL;
	new_node->key = key;
	new_node->value = value;
	if (!new_node)
		return (NULL);
	return (new_node);
}

void			*ash_bucket_set_node(
	t_bucket_node *node, char *key, void *value)
{
	void	*tmp;

	if (ash_strcmp(key, node->key) == 0)
	{
		tmp = node->value;
		node->value = value;
		return (tmp);
	}
	else if (node->next)
	{
		return (ash_bucket_set_node(node->next, key, value));
	}
	else
	{
		node->next = ash_create_node(key, value);
		return (NULL);
	}
}

void			*ash_bucket_set(t_bucket *bucket, char *key, void *value)
{
	if (bucket->node_count == 0)
	{
		bucket->nodes = ash_create_node(key, value);
		bucket->node_count += 1;
		return (NULL);
	}
	else
	{
		bucket->node_count += 1;
		return (ash_bucket_set_node(bucket->nodes, key, value));
	}
}
