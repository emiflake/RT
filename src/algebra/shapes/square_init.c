/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   square_init.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/12 23:16:16 by nmartins       #+#    #+#                */
/*   Updated: 2019/11/12 23:21:13 by nmartins      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "shape.h"

bool					square_init(
	t_shape *shape_out, const t_json_value *value)
{
	t_square	*square;

	shape_out->type = SHAPE_SQUARE;
	square = &shape_out->val.as_square;
	dict_def_vec(value, "origin", (t_vec){0, 0, 0}, &square->plane.origin);
	dict_def_vec(value, "side_a", (t_vec){0, 0, 0}, &square->side_a);
	dict_def_vec(value, "side_b", (t_vec){0, 0, 0}, &square->side_b);
	square->plane.normal = vec_cross(&square->side_b, &square->side_a);
	vec_normalize(&square->plane.normal);
	square->dot_a = vec_dot(&square->side_a, &square->side_a);
	square->dot_b = vec_dot(&square->side_b, &square->side_b);
	return (true);
}

void					square_set(t_square *square, t_vec origin,
							t_vec point_a, t_vec point_b)
{
	square->side_a = vec_sub(&point_a, &origin);
	square->dot_a = vec_dot(&square->side_a, &square->side_a);
	square->side_b = vec_sub(&point_b, &origin);
	square->dot_b = vec_dot(&square->side_b, &square->side_b);
	square->plane.origin = origin;
	square->plane.normal = vec_cross(&square->side_a, &square->side_b);
}

void					square_set_side(t_square *square, t_vec *origin,
							t_vec *side_a, t_vec *side_b)
{
	square->side_a = *side_a;
	square->dot_a = vec_dot(&square->side_a, &square->side_a);
	square->side_b = *side_b;
	square->dot_b = vec_dot(&square->side_b, &square->side_b);
	square->plane.origin = *origin;
	square->plane.normal = vec_cross(&square->side_a, &square->side_b);
}
