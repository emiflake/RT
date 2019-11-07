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

void	triangle_intersection(const t_ray *ray, t_intersection *intrs)
{
	(void)intrs;
	(void)ray;
}

bool	is_triangle_intersect(const t_shape *shape, const t_ray *ray,
							t_intersection *intrs)
{
	t_vec				orig_to_inters;
	t_shape				shape2;
	const t_triangle	*triangle;
	t_vec				intrs_vecs[3];

	triangle = &(shape->val.as_triangle);
	shape2.val.as_plane = triangle->plane;
	if (is_plane_intersect(&shape2, ray, intrs))
	{
		intrs_vecs[0] = vec_sub(&intrs->p, &triangle->plane.origin);
		intrs_vecs[1] = vec_sub(&intrs->p, &triangle->point_b);
		intrs_vecs[2] = vec_sub(&intrs->p, &triangle->point_c);
		if (vec_dot(&vec_cross(&triangle->side_a_b, intrs_vecs[0]), &triangle->plane.normal) >= 0 &&
			vec_dot(&vec_cross(&triangle->side_b_c, intrs_vecs[1]), &triangle->plane.normal) >= 0 &&
			vec_dot(&vec_cross(&triangle->side_b_c, intrs_vecs[2]), &triangle->plane.normal) >= 0)
			return (true);
	}
	return (false);
}
