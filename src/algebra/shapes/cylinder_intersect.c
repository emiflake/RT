/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cylinder_intersect.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: pacovali <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/12 18:56:23 by pacovali       #+#    #+#                */
/*   Updated: 2019/11/07 19:03:58 by nmartins      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "core/object/object.h"
#include "shape.h"
#include <stdio.h>

void		cylinder_intersection(const t_ray *ray, t_intersection *intrs)
{
	(void)ray;
	(void)intrs;
}

static void	find_abc(t_vec *abc, const t_ray *ray, const t_cylinder *cylinder)
{
	t_vec		distance;
	t_vec		tmp;

	distance = vec_sub(&ray->o, &cylinder->origin);
	tmp.x = vec_dot(&ray->d, &cylinder->axis);
	tmp.y = vec_dot(&distance, &cylinder->axis);
	abc->x = vec_dot(&ray->d, &ray->d) - tmp.x * tmp.x;
	abc->y = 2 * (vec_dot(&ray->d, &distance) - (tmp.x * tmp.y));
	abc->z = vec_dot(&distance, &distance) - (tmp.y * tmp.y)
			- (cylinder->radius * cylinder->radius);
}

static bool	find_normal(const t_ray *ray, t_cylinder *cylinder,
					t_intersection *intrs, REAL distance)
{
	t_vec		surf_point;
	t_vec		axis_point;
	t_vec		origin_to_intersection;
	REAL		length;

	if (distance < 0)
		return (false);
	surf_point = vec_adds(ray->o, vec_mults_scalar(ray->d, distance));
	origin_to_intersection = vec_sub(&cylinder->origin, &surf_point);
	length = -vec_dot(&origin_to_intersection, &cylinder->axis);
	if (length > cylinder->pos_height || length < cylinder->neg_height)
		return (false);
	intrs->t = distance;
	intrs->p = surf_point;
	axis_point = vec_adds(cylinder->origin,
							vec_mults_scalar(cylinder->axis, length));
	intrs->normal = vec_sub(&intrs->p, &axis_point);
	vec_normalize(&intrs->normal);
	return (true);
}

bool		is_cylinder_intersect(const t_shape *shape, const t_ray *ray,
							t_intersection *intrs)
{
	t_vec		abc;
	REAL		discr;
	t_point2	root;
	t_cylinder	*cylinder;

	cylinder = (t_cylinder*)&shape->val.as_cylinder;
	find_abc(&abc, ray, cylinder);
	discr = abc.y * abc.y - (4 * abc.x * abc.z);
	if (discr < 0)
		return (0);
	root = quad_eq(discr, abc.x, abc.y);
	if (root.x <= intrs->t && find_normal(ray, cylinder, intrs, root.x))
		return (true);
	if (root.y <= intrs->t && find_normal(ray, cylinder, intrs, root.y))
	{
		vec_negate(&intrs->normal);
		return (true);
	}
	return (false);
}
