/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sphere_bbox.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/15 16:40:07 by nmartins       #+#    #+#                */
/*   Updated: 2019/11/15 16:41:43 by nmartins      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "shape.h"

t_bbox					sphere_bbox(const t_shape *shape)
{
	const t_sphere *s = &shape->val.as_sphere;

	return ((t_bbox){
		.min = vec_subs(s->origin, (t_vec){s->radius, s->radius, s->radius}),
		.max = vec_adds(s->origin, (t_vec){s->radius, s->radius, s->radius}),
	});
}
