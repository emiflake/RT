/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   plane_bbox.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/15 23:33:33 by nmartins       #+#    #+#                */
/*   Updated: 2019/11/15 23:36:23 by nmartins      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "shape.h"

t_bbox					plane_bbox(const t_shape *shape)
{
	const t_plane *s = &shape->val.as_plane;

	return ((t_bbox){
		.min = vec_subs(s->origin, (t_vec){1000.0, 1000.0, 1000.0}),
		.max = vec_adds(s->origin, (t_vec){1000.0, 1000.0, 1000.0}),
	});
}
