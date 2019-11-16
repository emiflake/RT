/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cylinder_init.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/13 01:00:23 by nmartins       #+#    #+#                */
/*   Updated: 2019/11/13 01:04:02 by nmartins      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "shape.h"

bool	cylinder_init(t_shape *shape_out, const t_json_value *value)
{
	t_cylinder	*cylinder;

	shape_out->type = SHAPE_CYLINDER;
	cylinder = &shape_out->val.as_cylinder;
	dict_def_vec(value, "origin", (t_vec){0, 0, 0}, &cylinder->origin);
	dict_def_vec(value, "axis", (t_vec){0, 0, 0}, &cylinder->axis);
	cylinder->radius = dict_def_double(value, "radius", 0.0);
	cylinder->pos_height = dict_def_double(value, "pos_height", 0.0);
	cylinder->neg_height = dict_def_double(value, "neg_height", 0.0);
	return (true);
}
