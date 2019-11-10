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
	t_shape				shape2;
	const t_triangle	*triangle;
	t_vec				intrs_vecs[6];
	t_intersection 		tmp_intrs;

	triangle = &(shape->val.as_triangle);
	shape2.val.as_plane = triangle->plane;
	tmp_intrs = *intrs;
	if (is_plane_intersect(&shape2, ray, intrs))
	{
		intrs_vecs[0] = vec_sub(&intrs->p, &triangle->plane.origin);
		intrs_vecs[1] = vec_sub(&intrs->p, &triangle->point_b);
		intrs_vecs[2] = vec_sub(&intrs->p, &triangle->point_c);
		intrs_vecs[3] = vec_cross(&triangle->side_a_b, &intrs_vecs[0]);
		intrs_vecs[4] = vec_cross(&triangle->side_b_c, &intrs_vecs[1]);
		intrs_vecs[5] = vec_cross(&triangle->side_c_a, &intrs_vecs[2]);
		if (vec_dot(&intrs_vecs[3], &triangle->plane.normal) >= 0 &&
			vec_dot(&intrs_vecs[4], &triangle->plane.normal) >= 0 &&
			vec_dot(&intrs_vecs[5], &triangle->plane.normal) >= 0)
			return (true);
		*intrs = tmp_intrs;
	}
	return (false);
}
