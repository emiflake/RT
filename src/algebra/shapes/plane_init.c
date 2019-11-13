/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   plane_init.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/12 18:18:05 by nmartins       #+#    #+#                */
/*   Updated: 2019/11/12 20:23:47 by nmartins      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>
#include "shape.h"

bool					plane_init(
	t_shape *shape_out, const t_json_value *value)
{
	t_plane	*plane;

	shape_out->type = SHAPE_PLANE;
	plane = &shape_out->val.as_plane;
	dict_def_vec(value, "origin", (t_vec){0, 0, 0}, &plane->origin);
	dict_def_vec(value, "normal", (t_vec){0, 0, 0}, &plane->normal);
	return (true);
}
