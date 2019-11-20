/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   triangle_init.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/13 01:10:30 by nmartins       #+#    #+#                */
/*   Updated: 2019/11/13 01:13:12 by nmartins      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "shape.h"

bool	triangle_init(t_shape *shape_out, const t_json_value *value)
{
	t_triangle	*tri;

	shape_out->type = SHAPE_TRIANGLE;
	tri = &shape_out->val.as_triangle;
	dict_def_vec(value, "a_pos", (t_vec){0, 0, 0}, &tri->point[0]);
	dict_def_vec(value, "b_pos", (t_vec){0, 0, 0}, &tri->point[1]);
	dict_def_vec(value, "c_pos", (t_vec){0, 0, 0}, &tri->point[2]);
	dict_def_vec(value, "a_normal", (t_vec){0, 0, 0}, &tri->normal[0]);
	dict_def_vec(value, "b_normal", (t_vec){0, 0, 0}, &tri->normal[1]);
	dict_def_vec(value, "c_normal", (t_vec){0, 0, 0}, &tri->normal[2]);
	vec_normalize(&tri->normal[0]);
	vec_normalize(&tri->normal[1]);
	vec_normalize(&tri->normal[2]);
	tri->side[0] = vec_sub(&tri->point[1], &tri->point[0]);
	tri->side[1] = vec_sub(&tri->point[2], &tri->point[0]);
	return (true);
}

void	triangle_set(t_triangle *tri, t_vec a_pos, t_vec b_pos, t_vec c_pos)
{
	tri->point[0] = a_pos;
	tri->point[1] = b_pos;
	tri->point[2] = c_pos;
	tri->side[0] = vec_sub(&tri->point[1], &tri->point[0]);
	tri->side[1] = vec_sub(&tri->point[2], &tri->point[0]);
	tri->normal[0] = vec_cross(&tri->side[0], &tri->side[1]);
	vec_normalize(&tri->normal[0]);
	tri->normal[1] = tri->normal[0];
	tri->normal[2] = tri->normal[0];
}
