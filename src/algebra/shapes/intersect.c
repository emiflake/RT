/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   intersect.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: pacovali <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/12 18:56:23 by pacovali       #+#    #+#                */
/*   Updated: 2019/11/12 18:38:16 by nmartins      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

#include "shape.h"

void	intersection(
			const t_shape *shape, const t_ray *ray, t_intersection *isect)
{
	const t_inter_fn	fns[] = {
		&sphere_intersecton, &plane_intersection, &disk_intersection,
		&square_intersection, &triangle_intersection, &cylinder_intersection,
		&cone_intersection, &cube_intersection
	};

	fns[shape->type](ray, isect);
}

bool	is_intersect(
			const t_shape *shape, const t_ray *ray, t_intersection *isect)
{
	const t_is_inter_fn	fns[] = {
		&is_sphere_intersect, &is_plane_intersect, &is_disk_intersect,
		&is_square_intersect, &is_triangle_intersect, &is_cylinder_intersect,
		&is_cone_intersect, &is_cube_intersect
	};

	return (fns[shape->type](shape, ray, isect));
}
