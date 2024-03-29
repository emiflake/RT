/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cone_bbox.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/13 01:00:23 by nmartins       #+#    #+#                */
/*   Updated: 2019/11/13 01:04:02 by nmartins      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "shape.h"
#include "../bbox/bbox.h"

t_bbox		cone_bbox(const t_shape *shape)
{
	const t_cone	*s = &shape->val.as_cone;
	REAL			length;
	t_bbox			aggr;

	length = ((s->pos_height - s->neg_height) +
			(s->pos_height - s->neg_height) * tan(deg_to_rad(s->angle_deg)));
	aggr = (t_bbox){(t_vec){s->origin.x - length,
							s->origin.y - length,
							s->origin.z - length},
					(t_vec){s->origin.x + length,
							s->origin.y + length,
							s->origin.z + length}};
	return (aggr);
}
