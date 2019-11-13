/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cube_init.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/13 00:05:41 by nmartins       #+#    #+#                */
/*   Updated: 2019/11/13 01:00:56 by nmartins      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "shape.h"

// typedef struct		s_cube
// {
// 	t_vec			origin;
// 	t_vec			size;
// 	t_vec			up_axis;
// 	t_vec			front_axis;
// 	t_vec			right_axis;
// 	t_square		side[6];
// }					t_cube;

bool					cube_init(
	t_shape *shape_out, const t_json_value *value)
{
	t_cube	*cube;

	(void)value;
	shape_out->type = SHAPE_CUBE;
	cube = &shape_out->val.as_cube;
	/* TODO */
	return (true);
}
