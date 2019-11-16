/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   bbox_construct.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/15 16:33:28 by nmartins       #+#    #+#                */
/*   Updated: 2019/11/15 23:41:40 by nmartins      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "shape.h"

t_bbox					bbox_construct(const t_shape *shape)
{
	const t_bbox_fn	fns[] = {
		&sphere_bbox, &plane_bbox, &disk_bbox,
		&square_bbox, &triangle_bbox, &cylinder_bbox,
		&cone_bbox, &cube_bbox, &pyramid_bbox, &tetrahedron_bbox
	};

	return (fns[shape->type](shape));
}
