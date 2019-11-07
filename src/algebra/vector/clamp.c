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
	aggregate_color->x = clamp(aggregate_color->x, 0.0, 255.0);
	aggregate_color->y = clamp(aggregate_color->y, 0.0, 255.0);
	aggregate_color->z = clamp(aggregate_color->z, 0.0, 255.0);
}
