/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sphere_init.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/12 18:14:10 by nmartins       #+#    #+#                */
/*   Updated: 2019/11/12 20:24:02 by nmartins      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

#include "shape.h"

bool					sphere_init(
	t_shape *shape_out, const t_json_value *value)
{
	t_sphere	*sphere;

	shape_out->type = SHAPE_SPHERE;
	sphere = &shape_out->val.as_sphere;
	sphere->radius = dict_def_double(value, "radius", 0);
	dict_def_vec(value, "origin", (t_vec){0, 0, 0}, &sphere->origin);
	dict_def_vec(value, "axis", (t_vec){0, 0, 0}, &sphere->axis[0]);
	vec_normalize(&sphere->axis[0]);
	sphere->axis[1] = (t_vec){-0.147, 0.864, 0.333};
	vec_normalize(&sphere->axis[1]);
	sphere->axis[2] = vec_cross(&sphere->axis[0], &sphere->axis[1]);
	vec_normalize(&sphere->axis[2]);
	sphere->axis[1] = vec_cross(&sphere->axis[0], &sphere->axis[2]);
	vec_normalize(&sphere->axis[1]);
	return (true);
}
