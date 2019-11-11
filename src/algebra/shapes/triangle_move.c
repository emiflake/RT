/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   triangle_move.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: pacovali <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/01 00:42:00 by pacovali      #+#    #+#                 */
/*   Updated: 2019/01/01 00:42:01 by pacovali      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "shape.h"

bool	triangle_move(t_shape *shape, t_vec *direction, REAL distance)
{
	vec_mult_mut_scalar(direction, distance);
	vec_add_mut(&shape->val.as_triangle.plane.origin, direction);
	vec_add_mut(&shape->val.as_triangle.point_b, direction);
	vec_add_mut(&shape->val.as_triangle.point_c, direction);
	return (true);
}
