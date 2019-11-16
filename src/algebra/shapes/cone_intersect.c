/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cone_intersect.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: pacovali <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/12 18:56:23 by pacovali       #+#    #+#                */
/*   Updated: 2019/11/07 19:03:58 by nmartins      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

# include "core/object/object.h"
# include "shape.h"
# include <stdio.h>

void	cone_intersection(const t_ray *ray, t_intersection *intrs)
{
	(void)ray;
	(void)intrs;
}

static void		find_abc(t_vec *abc, const t_ray *ray, const t_cone *cone)
{
	t_point2	tmp;
	t_vec		distance;

	distance = vec_sub(&ray->o, &cone->origin);
	tmp.x = vec_dot(&ray->d, &cone->axis);
	tmp.y = vec_dot(&distance, &cone->axis);
	abc->x = tmp.x * tmp.x - cone->cos_angle * cone->cos_angle;
	abc->y = 2 * (tmp.x * tmp.y - vec_dot(&ray->d, &distance) * \
					cone->cos_angle * cone->cos_angle);
	abc->z = tmp.y * tmp.y - vec_dot(&distance, &distance) * \
					cone->cos_angle * cone->cos_angle;
}

static bool		find_normal(const t_ray *ray, t_cone *cone,
					t_intersection *intrs, REAL distance)
{
	t_vec		surf_point;
	t_vec		axis_point;
	t_vec		origin_to_intersection;
	REAL		length;

	if (distance < 0 || distance > intrs->t)
		return (false);
	surf_point = vec_adds(ray->o, vec_mults_scalar(ray->d, distance));
	origin_to_intersection = vec_sub(&surf_point, &cone->origin);
	length = vec_dot(&origin_to_intersection, &cone->axis);
	if (length > cone->pos_height || length < cone->neg_height)
		return (false);
	intrs->t = distance;
	intrs->p = surf_point;
	axis_point = vec_adds(cone->origin, vec_mults_scalar(cone->axis, length));
	intrs->normal = vec_sub(&intrs->p, &axis_point);
	vec_normalize(&intrs->normal);
	return (true);
}

bool			is_cone_intersect(const t_shape *shape, const t_ray *ray,
							t_intersection *intrs)
{
	t_vec		abc;
	REAL		discr;
	t_point2	root;
	t_cone		*cone;
	bool		res;

	res = false;
	cone = (t_cone*)&shape->val.as_cone;
	find_abc(&abc, ray, cone);
	discr = abc.y * abc.y - (4 * abc.x * abc.z);
	if (discr < 0)
		return (res);
	root = quad_eq(discr, abc.x, abc.y);
	res = find_normal(ray, cone, intrs, root.y);
	if (find_normal(ray, cone, intrs, root.x))
	{
		vec_negate(&intrs->normal);
		res = true;
	}
	return (res);
}
