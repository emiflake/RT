/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   square_bbox.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/15 23:36:55 by nmartins       #+#    #+#                */
/*   Updated: 2019/11/15 23:40:00 by nmartins      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "shape.h"

t_bbox					square_bbox(const t_shape *shape)
{
	const t_square	*s = &shape->val.as_square;
	t_bbox			aggr;

	aggr = (t_bbox){(t_vec){INFINITY, INFINITY, INFINITY},
					(t_vec){-INFINITY, -INFINITY, -INFINITY}};
	bbox_extend_mut(&aggr, s->plane.origin);
	bbox_extend_mut(&aggr, vec_adds(s->plane.origin, s->side_a));
	bbox_extend_mut(&aggr, vec_adds(s->plane.origin, s->side_b));
	bbox_extend_mut(&aggr, vec_adds(vec_adds(s->plane.origin, s->side_b), s->side_a));
	return (aggr);
}
