/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   square_intersect.c                                           :+:    :+:  */
/*                                                     +:+                    */
/*   By: pacovali <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/01 00:42:00 by pacovali      #+#    #+#                 */
/*   Updated: 2019/01/01 00:42:01 by pacovali      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "shape.h"

bool	square_intersection(const t_ray *ray, t_intersection *intrs)
{
	if (ray == 0)
		ray = 0;
	if (intrs == 0)
		intrs = 0;
	return (true);
}

bool	is_square_intersect(const t_shape *shape, const t_ray *ray,
							t_intersection *intrs)
{
	t_vec			orig_to_inters;
	const t_square	*square;
	REAL 			dist_a;
	REAL 			dist_b;
	t_shape			shape2;

	square = &(shape->val.as_square);
	shape2.val.as_plane = square->plane;
	if (is_plane_intersect(&shape2, ray, intrs))
	{
		orig_to_inters = vec_sub(&intrs->p, &square->plane.origin);
		dist_a = vec_dot(&orig_to_inters, &(square->side_a));
		dist_b = vec_dot(&orig_to_inters, &(square->side_b));
		if (dist_a >= 0 && dist_b >= 0 \
			&& dist_a < square->dot_a && dist_b < square->dot_b)
			return (true);
	}
	return (false);
}
