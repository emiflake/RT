/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pyramid_move.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: pacovali <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/01 00:42:00 by pacovali      #+#    #+#                 */
/*   Updated: 2019/01/01 00:42:01 by pacovali      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "shape.h"

bool	pyramid_move(t_shape *shape, t_vec *direction, REAL distance)
{
	t_pyramid	*pyr;

	pyr = &shape->val.as_pyramid;
	vec_mult_mut_scalar(direction, distance);
	vec_add_mut(&pyr->origin, direction);
	vec_add_mut(&pyr->point[0], direction);
	vec_add_mut(&pyr->point[1], direction);
	vec_add_mut(&pyr->point[2], direction);
	vec_add_mut(&pyr->point[3], direction);
	triangle_set(&pyr->side[0], pyr->point[0], pyr->origin, pyr->point[1]);
	triangle_set(&pyr->side[1], pyr->point[1], pyr->origin, pyr->point[2]);
	triangle_set(&pyr->side[2], pyr->point[2], pyr->origin, pyr->point[3]);
	triangle_set(&pyr->side[3], pyr->point[3], pyr->origin, pyr->point[0]);
	triangle_set(&pyr->side[4], pyr->point[1], pyr->origin, pyr->point[0]);
	triangle_set(&pyr->side[5], pyr->point[2], pyr->origin, pyr->point[1]);
	triangle_set(&pyr->side[6], pyr->point[3], pyr->origin, pyr->point[2]);
	triangle_set(&pyr->side[7], pyr->point[0], pyr->origin, pyr->point[3]);
	square_set(&pyr->base, pyr->point[0], pyr->point[1], pyr->point[2]);
	return (true);
}
