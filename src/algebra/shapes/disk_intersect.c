/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   disk_intersect.c                                             :+:    :+:  */
/*                                                     +:+                    */
/*   By: pacovali <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/01 00:42:00 by pacovali      #+#    #+#                 */
/*   Updated: 2019/01/01 00:42:01 by pacovali      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "shape.h"

bool	disk_intersection(const t_ray *ray, t_intersection *intrs)
{
	if (ray == 0)
		ray = 0;
	if (intrs == 0)
		intrs = 0;
	return (true);
}

bool	is_disk_intersect(const t_shape *shape, const t_ray *ray,
						t_intersection *intrs)
{
	t_vec			orig_to_inters;
	const t_disk	*disk;
	t_shape			shape2;

	disk = &shape->val.as_disk;
	shape2.val.as_plane = disk->plane;
	if (is_plane_intersect(&shape2, ray, intrs))
	{
		orig_to_inters = vec_sub(&intrs->p, &(disk->plane.origin));
		if (vec_dot(&orig_to_inters, &orig_to_inters) <= disk->radius)
			return (true);
	}
	return (false);
}
