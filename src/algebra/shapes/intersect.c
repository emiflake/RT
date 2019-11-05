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


bool			intersect(
	const t_ray *ray, const t_shape *shape, t_intersection *isect)
{
	const t_inter_fn	fns[] = {
		sphere_intersect,
	};
	
	fns[shape->type](ray, shape, isect);
}
