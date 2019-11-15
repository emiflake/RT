/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   construct.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/15 16:30:12 by nmartins       #+#    #+#                */
/*   Updated: 2019/11/15 17:25:39 by nmartins      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "container.h"
#include <ft_printf.h>

t_bvh_node		*bvh_construct(const t_object_container_node *shapes)
{
	const t_object_container_node	*w;
	size_t							i;

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
	node->bounding_box = bbox_merges(left->bounding_box, right->bounding_box);
	node->left = left;
	node->right = right;
	node->object = NULL;
	return (node);
}

t_bvh_node		*bvh_construct_rec(const t_object_container_node *shapes,
	size_t count,
	size_t dimension)
{
	t_bbox							aggregate_bbox;
	const t_object_container_node	*node;
	size_t							i;

	(void)dimension;
	aggregate_bbox = (t_bbox){(t_vec){INFINITY, INFINITY, INFINITY},
							(t_vec){-INFINITY, -INFINITY, -INFINITY}};
	if (count == 0)
		return (NULL);
	else if (count == 1)
	{
		ft_printf("Built leaf\n");
		return (build_leaf(shapes->val));
	}
	else
	{
		i = 0;
		node = shapes;
		while (i < count / 2)
		{
			i++;
			node = node->next;
		}
		return (build_branch(
			bvh_construct_rec(shapes, (count + 1) / 2, 0),
			bvh_construct_rec(node, count / 2, 0)));
	}
}

void			bvh_debug_c(const t_bvh_node *node, size_t indent)
{
	if (!node)
	{
		ft_printf("%*sNULL\n", indent, "");
	}
	else if (node->object)
	{
		ft_printf("%*sobject\n", indent, "");
	}
	else
	{
		ft_printf("%*s{\n", indent, "");
		bvh_debug_c(node->left, indent + 4);
		bvh_debug_c(node->right, indent + 4);
		ft_printf("%*s}\n", indent, "");
	}
}

void			bvh_debug(const t_bvh_node *node)
{
	bvh_debug_c(node, 0);
}
