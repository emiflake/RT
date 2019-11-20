/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   triangle_bbox.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/13 01:00:23 by nmartins       #+#    #+#                */
/*   Updated: 2019/11/13 01:04:02 by nmartins      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "shape.h"
#include "../bbox/bbox.h"

t_bbox		triangle_bbox(const t_shape *shape)
{
	const t_triangle		*s = &shape->val.as_triangle;
	t_bbox					aggr;
	int						i;

	aggr = (t_bbox){(t_vec){INFINITY, INFINITY, INFINITY},
		(t_vec){-INFINITY, -INFINITY, -INFINITY}};
	i = 0;
	while (i < 3)
	{
		bbox_extend_mut(&aggr, s->point[i]);
		i++;
	}
	return (aggr);
}
