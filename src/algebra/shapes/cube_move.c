/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cube_move.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: pacovali <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/01 00:42:00 by pacovali      #+#    #+#                 */
/*   Updated: 2019/01/01 00:42:01 by pacovali      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "shape.h"

bool	cube_move(t_shape *shape, t_vec *direction, REAL distance)
{
	t_cube	*cube;

	cube = &shape->val.as_cube;
	vec_mult_mut_scalar(direction, distance);
	vec_add_mut(&shape->val.as_cube.origin, direction);
	cube_set_sides(cube);
	return (true);
}
