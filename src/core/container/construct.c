/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   construct.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/15 16:30:12 by nmartins       #+#    #+#                */
/*   Updated: 2019/11/20 17:24:04 by nmartins      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "container.h"
#include <ft_printf.h>
#include <assert.h>

t_bvh_node				*bvh_construct(t_object_container_node *shapes)
{
	t_object_container_node		*w;
	size_t						i;

	i = 0;
	w = shapes;
	while (w)
	{
		i++;
		w = w->next;
	}
	return (bvh_construct_rec(shapes, i, 0));
}

static t_bvh_node		*build_leaf(t_object *obj)
{
	t_bvh_node	*node;

	node = malloc(sizeof(t_bvh_node));
	if (!node)
		return (NULL);
	node->bounding_box = bbox_construct(&obj->shape);
	node->left = NULL;
	node->right = NULL;
	node->object = obj;
	return (node);
}

static t_bvh_node		*build_branch(t_bvh_node *left, t_bvh_node *right)
{
	t_bvh_node	*node;

	node = malloc(sizeof(t_bvh_node));
	if (!node)
		return (NULL);
	assert(left != NULL && right != NULL);
	node->bounding_box = bbox_merges(left->bounding_box, right->bounding_box);
	node->left = left;
	node->right = right;
	node->object = NULL;
	return (node);
}

static void				bvh_sort(
	t_object_container_node *shapes, size_t count, size_t dimension)
{
	t_object_container_node	*i;
	t_object_container_node	*j;
	t_object				*tmp;
	size_t					it[2];

	i = shapes;
	it[0] = 0;
	while (i && it[0] < count)
	{
		it[1] = it[0];
		j = i;
		while (j && it[1] < count)
		{
			if (bbox_cmp_center(i->val, j->val, dimension) > 0)
			{
				tmp = i->val;
				i->val = j->val;
				j->val = tmp;
			}
			j = j->next;
			it[1]++;
		}
		i = i->next;
		it[0]++;
	}
}

t_bvh_node				*bvh_construct_rec(t_object_container_node *shapes,
	size_t count,
	size_t dimension)
{
	t_object_container_node		*node;
	size_t						i;

	if (count == 0)
		return (NULL);
	else if (count == 1)
		return (build_leaf(shapes->val));
	else
	{
		bvh_sort(shapes, count, dimension);
		i = 0;
		node = shapes;
		while (i < count / 2)
		{
			i++;
			node = node->next;
		}
		return (build_branch(
			bvh_construct_rec(shapes, count / 2, (dimension + 1) % 3),
			bvh_construct_rec(node, (count + 1) / 2, (dimension + 1) % 3)));
	}
}
