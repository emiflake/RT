/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   tetrahedron_intersect.c                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: pacovali <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/01 00:42:00 by pacovali       #+#    #+#                */
/*   Updated: 2019/11/21 17:55:30 by nmartins      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "shape.h"

void	tetrahedron_intersection(const t_ray *ray, t_intersection *intrs)
{
	(void)ray;
	(void)intrs;
	intrs->uv.x = 0.5 + atan2(intrs->normal.z, intrs->normal.x) / M_PI / 2.0;
	intrs->uv.y = 0.5 - asin(intrs->normal.y) / M_PI;
}

bool	is_tetrahedron_intersect(const t_shape *shape, const t_ray *ray,
							t_intersection *intrs)
{
	int				i;
	t_shape			shape2;
	bool			found;

	found = false;
	i = 0;
	while (i < 8)
	{
		shape2.val.as_triangle = shape->val.as_tetrahedron.side[i];
		if (is_triangle_intersect(&shape2, ray, intrs))
			found = true;
		i++;
	}
	return (found);
}
