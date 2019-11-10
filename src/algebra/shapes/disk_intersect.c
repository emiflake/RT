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

void	disk_intersection(const t_ray *ray, t_intersection *intrs)
{
	(void)ray;
	(void)intrs;
}

bool	is_disk_intersect(const t_shape *shape, const t_ray *ray,
						t_intersection *intrs)
{
	t_vec			orig_to_inters;
	const t_disk	*disk;
	t_shape			shape2;
	t_intersection	tmp_intrs;
	REAL			distance;

	disk = &shape->val.as_disk;
	shape2.val.as_plane = disk->plane;
	tmp_intrs = *intrs;
	if (is_plane_intersect(&shape2, ray, &tmp_intrs))
	{
		orig_to_inters = vec_sub(&tmp_intrs.p, &(disk->plane.origin));
		distance = vec_dot(&orig_to_inters, &orig_to_inters);
		if (distance <= disk->outer_radius * disk->outer_radius &&
			distance >= disk->inner_radius * disk->inner_radius)
		{
			*intrs = tmp_intrs;
			return (true);
		}
	}
	return (false);
}
