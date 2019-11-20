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

void	square_intersection(const t_ray *ray, t_intersection *intrs)
{
	(void)ray;
	(void)intrs;
}

bool	is_square_intersect(const t_shape *shape, const t_ray *ray,
							t_intersection *intrs)
{
	t_vec			orig_to_inters;
	const t_square	*square;
	REAL			dist[2];
	t_intersection	tmp_intrs;
	t_shape			shape2;

	square = &(shape->val.as_square);
	shape2.val.as_plane = square->plane;
	tmp_intrs = *intrs;
	if (is_plane_intersect(&shape2, ray, intrs))
	{
		orig_to_inters = vec_sub(&intrs->p, &square->plane.origin);
		dist[0] = vec_dot(&orig_to_inters, &(square->side_a));
		dist[1] = vec_dot(&orig_to_inters, &(square->side_b));
		if (dist[0] >= 0 && dist[1] >= 0 \
			&& dist[0] < square->dot_a && dist[1] < square->dot_b)
			return (1);
		*intrs = tmp_intrs;
	}
	return (false);
}
