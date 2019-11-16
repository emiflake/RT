/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   compare_centers.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/16 00:31:19 by nmartins       #+#    #+#                */
/*   Updated: 2019/11/16 00:42:07 by nmartins      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "core/object/object.h"
#include "bbox.h"

int		bbox_cmp_center(struct s_object *a, struct s_object *b, size_t dim)
{
	t_bbox	ab;
	t_bbox	bb;
	t_vec	ac;
	t_vec	bc;

	ab = bbox_construct(&a->shape);
	bb = bbox_construct(&b->shape);
	ac = bbox_center(&ab);
	bc = bbox_center(&bb);
	if (dim == 0)
		return (ac.x > bc.x ? 1 : -1);
	if (dim == 1)
		return (ac.y > bc.y ? 1 : -1);
	if (dim == 2)
		return (ac.z > bc.z ? 1 : -1);
	return (0);
}
