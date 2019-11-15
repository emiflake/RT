/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   square_init.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/12 23:16:16 by nmartins       #+#    #+#                */
/*   Updated: 2019/11/13 16:23:55 by nmartins      ########   odam.nl         */
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
	dict_def_vec(value, "normal", (t_vec){0, 0, 0}, &square->plane.normal);
	dict_def_vec(value, "side_a", (t_vec){0, 0, 0}, &square->side_a);
	dict_def_vec(value, "side_b", (t_vec){0, 0, 0}, &square->side_b);
	square->dot_a = vec_dot(&square->side_a, &square->side_a);
	square->dot_b = vec_dot(&square->side_b, &square->side_b);
	return (true);
}
