/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cube_rotate.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: pacovali <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/01 00:42:00 by pacovali      #+#    #+#                 */
/*   Updated: 2019/01/01 00:42:01 by pacovali      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "shape.h"

bool	cube_rotate(t_shape *shape, t_vec *rotation_rad)
{
	t_cube	*cube;

	cube = &shape->val.as_cube;
	vec_normalize(&cube->axis[0]);
	vec_rotate_xyz(&cube->axis[0], rotation_rad);
	vec_normalize(&cube->axis[1]);
	vec_rotate_xyz(&cube->axis[1], rotation_rad);
	vec_normalize(&cube->axis[2]);
	vec_rotate_xyz(&cube->axis[2], rotation_rad);
	vec_mult_mut_scalar(&cube->axis[0], cube->size.y);
	vec_mult_mut_scalar(&cube->axis[1], cube->size.z);
	vec_mult_mut_scalar(&cube->axis[2], cube->size.x);
	cube_set_sides(cube);
	cube_check_normals(cube);
	return (true);
}
