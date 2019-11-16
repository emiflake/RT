/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   tetrahedron_init.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/13 01:10:30 by nmartins       #+#    #+#                */
/*   Updated: 2019/11/13 01:13:12 by nmartins      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "shape.h"

bool		tetrahedron_init(t_shape *shape_out, const t_json_value *value)
{
	t_tetrahedron	*tet;

	shape_out->type = SHAPE_TETRAHEDRON;
	tet = &shape_out->val.as_tetrahedron;
	dict_def_vec(value, "a_pos", (t_vec){0, 0, 0}, &tet->point[0]);
	dict_def_vec(value, "b_pos", (t_vec){0, 0, 0}, &tet->point[1]);
	dict_def_vec(value, "c_pos", (t_vec){0, 0, 0}, &tet->point[2]);
	dict_def_vec(value, "d_pos", (t_vec){0, 0, 0}, &tet->point[3]);
	triangle_set(&tet->side[0], tet->point[2], tet->point[3], tet->point[1]);
	triangle_set(&tet->side[1], tet->point[3], tet->point[0], tet->point[2]);
	triangle_set(&tet->side[2], tet->point[1], tet->point[0], tet->point[3]);
	triangle_set(&tet->side[3], tet->point[2], tet->point[0], tet->point[1]);
	triangle_set(&tet->side[4], tet->point[1], tet->point[3], tet->point[2]);
	triangle_set(&tet->side[5], tet->point[2], tet->point[0], tet->point[3]);
	triangle_set(&tet->side[6], tet->point[3], tet->point[0], tet->point[1]);
	triangle_set(&tet->side[7], tet->point[1], tet->point[0], tet->point[2]);
	return (true);
}
