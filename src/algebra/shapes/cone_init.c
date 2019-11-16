/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cone_init.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/13 01:00:23 by nmartins       #+#    #+#                */
/*   Updated: 2019/11/13 01:04:02 by nmartins      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "shape.h"

bool		cone_init(t_shape *shape_out, const t_json_value *value)
{
	t_cone	*cone;

	shape_out->type = SHAPE_CONE;
	cone = &shape_out->val.as_cone;
	dict_def_vec(value, "origin", (t_vec){0, 0, 0}, &cone->origin);
	dict_def_vec(value, "axis", (t_vec){0, 0, 0}, &cone->axis);
	cone->angle_deg = dict_def_double(value, "angle_deg", 0.0);
	cone->pos_height = dict_def_double(value, "pos_height", 0.0);
	cone->neg_height = dict_def_double(value, "neg_height", 0.0);
	cone->cos_angle = cos(deg_to_rad(cone->angle_deg));
	return (true);
}
