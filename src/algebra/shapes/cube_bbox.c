/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cube_bbox.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/13 01:00:23 by nmartins       #+#    #+#                */
/*   Updated: 2019/11/13 01:04:02 by nmartins      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "shape.h"
#include "../bbox/bbox.h"

t_bbox		cube_bbox(const t_shape *shape)
{
	const t_cube	*s = &shape->val.as_cube;
	t_bbox			aggr;

	aggr = (t_bbox){(t_vec){INFINITY, INFINITY, INFINITY},
		(t_vec){-INFINITY, -INFINITY, -INFINITY}};
	bbox_extend_mut(&aggr, s->origin);
	bbox_extend_mut(&aggr, vec_adds(s->origin, s->axis[0]));
	bbox_extend_mut(&aggr, vec_adds(s->origin, s->axis[1]));
	bbox_extend_mut(&aggr, vec_adds(s->origin,
									vec_adds(s->axis[0], s->axis[1])));
	bbox_extend_mut(&aggr, vec_adds(s->origin, s->axis[2]));
	bbox_extend_mut(&aggr, vec_adds(vec_adds(s->origin, s->axis[2]),
									s->axis[0]));
	bbox_extend_mut(&aggr, vec_adds(vec_adds(s->origin, s->axis[2]),
									s->axis[1]));
	bbox_extend_mut(&aggr, vec_adds(vec_adds(s->origin, s->axis[2]),
									vec_adds(s->axis[0], s->axis[1])));
	return (aggr);
}
