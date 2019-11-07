/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   intersect.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: pacovali <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/12 18:56:23 by pacovali      #+#    #+#                 */
/*   Updated: 2019/01/23 17:53:36 by pacovali      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "shape.h"

bool	is_intersect(
			const t_shape *shape, const t_ray *ray, t_intersection *isect)
{
	const t_is_inter_fn	fns[] = {
		&is_sphere_intersect, &is_plane_intersect, &is_disk_intersect,
		&is_square_intersect
	};

	return(fns[shape->type](shape, ray, isect));
}

bool	intersection(
			const t_shape *shape, const t_ray *ray, t_intersection *isect)
{
	const t_inter_fn	fns[] = {
		&sphere_intersecton, &plane_intersection, &disk_intersection,
		&square_intersection
	};

	return(fns[shape->type](ray, isect));
}
