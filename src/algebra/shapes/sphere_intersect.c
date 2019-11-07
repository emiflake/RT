/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sphere_intersect.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: pacovali <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/12 18:56:23 by pacovali      #+#    #+#                 */
/*   Updated: 2019/01/23 17:53:36 by pacovali      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

# include "shape.h"

void	sphere_intersecton(const t_ray *ray, t_intersection *intrs)
{
	t_sphere	*sphere;

	sphere = &(intrs->obj_ptr->shape.val.as_sphere);
	intrs->p = vec_mults_scalar(ray->d, intrs->t);
	intrs->p = vec_add(&ray->o, &intrs->p);
	intrs->normal = vec_sub(&intrs->p, &sphere->origin);
	vec_normalize(&intrs->normal);
}

bool	is_sphere_intersect(const t_shape *shape, const t_ray *ray,
						t_intersection *intrs)
{
	t_vec			abc;
	REAL			discr;
	REAL			root;
	t_vec			distance;
	const t_sphere	*sphere;

	sphere = &shape->val.as_sphere;
	distance = vec_sub(&ray->o, &sphere->origin);
	abc.x = vec_dot(&ray->d, &ray->d);
	abc.y = 2 * vec_dot(&distance, &ray->d);
	abc.z = vec_dot(&distance, &distance) - (sphere->radius * sphere->radius);
	discr = (abc.y * abc.y) - (4 * abc.x * abc.z);
	if (discr < 0)
		return (false);
	root = quad_eq(&discr, &abc.x, &abc.y);
	if (root < 0)
		return (false);
	intrs->t = root;
	return (true);
}
