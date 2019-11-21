/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cube_init.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/13 00:05:41 by nmartins       #+#    #+#                */
/*   Updated: 2019/11/21 19:44:06 by nmartins      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "shape.h"

void	cube_check_normals(t_cube *cube)
{
	if (vec_dot(&cube->side[0].plane.normal, &cube->axis[1]) > 0)
		vec_negate(&cube->side[0].plane.normal);
	if (vec_dot(&cube->side[3].plane.normal, &cube->axis[1]) < 0)
		vec_negate(&cube->side[3].plane.normal);
	if (vec_dot(&cube->side[1].plane.normal, &cube->axis[0]) > 0)
		vec_negate(&cube->side[1].plane.normal);
	if (vec_dot(&cube->side[4].plane.normal, &cube->axis[0]) < 0)
		vec_negate(&cube->side[4].plane.normal);
	if (vec_dot(&cube->side[2].plane.normal, &cube->axis[2]) > 0)
		vec_negate(&cube->side[2].plane.normal);
	if (vec_dot(&cube->side[5].plane.normal, &cube->axis[2]) < 0)
		vec_negate(&cube->side[5].plane.normal);
}

void	cube_set_sides(t_cube *cube)
{
	t_vec	tmp;

	square_set_side(&cube->side[0], &cube->origin, &cube->axis[2],
					&cube->axis[0]);
	tmp = vec_add(&cube->origin, &cube->axis[1]);
	square_set_side(&cube->side[3], &tmp, &cube->axis[2], &cube->axis[0]);
	square_set_side(&cube->side[1], &cube->origin, &cube->axis[2],
					&cube->axis[1]);
	tmp = vec_add(&cube->origin, &cube->axis[0]);
	square_set_side(&cube->side[4], &tmp, &cube->axis[2], &cube->axis[1]);
	square_set_side(&cube->side[2], &cube->origin, &cube->axis[1],
					&cube->axis[0]);
	tmp = vec_add(&cube->origin, &cube->axis[2]);
	square_set_side(&cube->side[5], &tmp, &cube->axis[1], &cube->axis[0]);
}

bool	cube_init(t_shape *shape_out, const t_json_value *value)
{
	t_cube	*cube;

	shape_out->type = SHAPE_CUBE;
	cube = &shape_out->val.as_cube;
	dict_def_vec(value, "origin", (t_vec){0, 0, 0}, &cube->origin);
	dict_def_vec(value, "axis_vert", (t_vec){0, 0, 0}, &cube->axis[0]);
	dict_def_vec(value, "size", (t_vec){0, 0, 0}, &cube->size);
	vec_normalize(&cube->axis[0]);
	cube->axis[1] = (t_vec){0.0, 1.0, 0.0};
	cube->axis[2] = vec_cross(&cube->axis[0], &cube->axis[1]);
	vec_normalize(&cube->axis[2]);
	cube->axis[1] = vec_cross(&cube->axis[0], &cube->axis[2]);
	vec_normalize(&cube->axis[1]);
	vec_mult_mut_scalar(&cube->axis[0], cube->size.y);
	vec_mult_mut_scalar(&cube->axis[1], cube->size.z);
	vec_mult_mut_scalar(&cube->axis[2], cube->size.x);
	cube_set_sides(cube);
	cube_check_normals(cube);
	return (true);
}
