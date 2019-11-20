/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   disk_bbox.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/13 01:00:23 by nmartins       #+#    #+#                */
/*   Updated: 2019/11/13 01:04:02 by nmartins      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "shape.h"
#include "../bbox/bbox.h"

t_bbox		disk_bbox(const t_shape *shape)
{
	const t_disk	*s = &shape->val.as_disk;
	t_bbox			aggr;

	aggr = (t_bbox){(t_vec){s->plane.origin.x - s->outer_radius,
							s->plane.origin.y - s->outer_radius,
							s->plane.origin.z - s->outer_radius},
					(t_vec){s->plane.origin.x + s->outer_radius,
							s->plane.origin.y + s->outer_radius,
							s->plane.origin.z + s->outer_radius}};
	return (aggr);
}
