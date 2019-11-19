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
	pyramid_set_sides(pyr);
	return (true);
}
