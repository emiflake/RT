/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   intersect.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/07 16:20:54 by nmartins       #+#    #+#                */
/*   Updated: 2019/11/07 18:32:11 by nmartins      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

#include "algebra/shapes/shape.h"

#include "container.h"

bool	container_is_intersect(
	const t_object_container *container,
	const t_ray *ray, t_intersection *isect)
{
	size_t					count;
	bool					did_find;
	t_object_container_node	*curr_node;

	did_find = false;
	curr_node = container->root;
	count = 0;
	while (curr_node)
	{
		count++;
		if (is_intersect(&curr_node->val->shape, ray, isect))
		{
			isect->obj_ptr = curr_node->val;
			did_find = true;
		}
		curr_node = curr_node->next;
	}
	return (did_find);
}
