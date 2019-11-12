/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   clamp.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/07 17:36:43 by nmartins       #+#    #+#                */
/*   Updated: 2019/11/07 17:38:37 by nmartins      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"
#include "algebra/mmath/mmath.h"

void	vec_color_clamp_mut(t_vec *aggregate_color)
{
	REAL	max_v;
	REAL	min_v;

	min_v = min(min(aggregate_color->x, aggregate_color->y), aggregate_color->z);
	if (min_v < 0)
	{
		min_v = - min_v;
		aggregate_color->x += min_v;
		aggregate_color->y += min_v;
		aggregate_color->z += min_v;
	}
	max_v = max(max(aggregate_color->x, aggregate_color->y), aggregate_color->z);
	if (max_v > 255.0)
	{
		max_v = 255.0 / max_v;
		aggregate_color->x *= max_v;
		aggregate_color->y *= max_v;
		aggregate_color->z *= max_v;
	}
	/*
	aggregate_color->x = clamp(aggregate_color->x, 0.0, 255.0);
	aggregate_color->y = clamp(aggregate_color->y, 0.0, 255.0);
	aggregate_color->z = clamp(aggregate_color->z, 0.0, 255.0);
	 */
}
