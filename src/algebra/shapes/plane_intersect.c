/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   plane_intersect.c                                            :+:    :+:  */
/*                                                     +:+                    */
/*   By: pacovali <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/01 00:42:00 by pacovali      #+#    #+#                 */
/*   Updated: 2019/01/01 00:42:01 by pacovali      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "shape.h"

bool	plane_intersection(const t_ray *ray, t_intersection *intrs)
{
	if (ray == 0)
		ray = 0;
	if (intrs == 0)
		intrs = 0;
	return (true);
}

bool	is_plane_intersect(const t_shape *shape, const t_ray *ray,
						t_intersection *intrs)
{
	const t_plane	*plane;
	t_vec			ray_to_origin;
	t_vec			ray_to_inters;
	REAL			distance;

	plane = &(shape->val.as_plane);
	ray_to_origin = vec_sub(&plane->origin, &ray->o);
	distance = -vec_dot(&ray_to_origin, &plane->normal) / \
				-vec_dot(&plane->normal, &ray->d);
	if (distance > 0 && distance < intrs->t)
	{
		intrs->t = distance;
		intrs->normal = plane->normal;
		ray_to_inters = vec_mults_scalar(ray->d, distance);
		intrs->p = vec_add(&ray->o, &ray_to_inters);
		return (true);
	}
	return (false);
}
