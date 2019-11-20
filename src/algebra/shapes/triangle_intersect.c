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
#include <stdio.h>

void			triangle_intersection(const t_ray *ray, t_intersection *intrs)
{
	(void)intrs;
	(void)ray;
}

static void		set_intersection(t_triangle triangle, t_vec uvt,
						t_intersection *intrs, const t_ray *ray)
{
	t_vec	tmp[3];

	tmp[0] = vec_mults_scalar(triangle.normal[0], 1 - uvt.x - uvt.y);
	tmp[1] = vec_mults_scalar(triangle.normal[1], uvt.x);
	tmp[2] = vec_mults_scalar(triangle.normal[2], uvt.y);
	vec_add_mut(&tmp[1], &tmp[2]);
	vec_add_mut(&tmp[0], &tmp[1]);
	intrs->normal = vec_normalized(&tmp[0]);
	intrs->t = uvt.z;
	tmp[0] = vec_mults_scalar(ray->d, intrs->t);
	intrs->p = vec_add(&ray->o, &tmp[0]);
	intrs->uv.x = uvt.x;
	intrs->uv.y = uvt.y;
}

bool			is_triangle_intersect(const t_shape *shape, const t_ray *ray,
							t_intersection *intrs)
{
	t_vec		orthogonal_vector;
	t_vec		distance;
	t_vec		uvt;
	REAL		det;

	orthogonal_vector = vec_cross(&ray->d, &shape->val.as_triangle.side[1]);
	det = vec_dot(&shape->val.as_triangle.side[0], &orthogonal_vector);
	if ((det < 0 && -det < EPS) || det < EPS)
		return (false);
	det = 1 / det;
	distance = vec_sub(&ray->o, &shape->val.as_triangle.point[0]);
	uvt.x = vec_dot(&distance, &orthogonal_vector) * det;
	if (uvt.x < 0 || uvt.x > 1.0)
		return (false);
	orthogonal_vector = vec_cross(&distance, &shape->val.as_triangle.side[0]);
	uvt.y = vec_dot(&ray->d, &orthogonal_vector) * det;
	if (uvt.y < 0 || (uvt.x + uvt.y) > 1.0)
		return (false);
	uvt.z = vec_dot(&shape->val.as_triangle.side[1], &orthogonal_vector) * det;
	if (uvt.z < 0 || uvt.z > intrs->t)
		return (false);
	set_intersection(shape->val.as_triangle, uvt, intrs, ray);
	return (true);
}
