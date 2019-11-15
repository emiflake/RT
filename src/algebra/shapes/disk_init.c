/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   disk_init.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/13 01:00:23 by nmartins       #+#    #+#                */
/*   Updated: 2019/11/13 16:23:58 by nmartins      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "shape.h"

bool					disk_init(
	t_shape *shape_out, const t_json_value *value)
{
	t_disk	*disk;

	shape_out->type = SHAPE_DISK;
	disk = &shape_out->val.as_disk;
	dict_def_vec(value, "origin", (t_vec){0, 0, 0}, &disk->plane.origin);
	dict_def_vec(value, "normal", (t_vec){0, 0, 0}, &disk->plane.normal);
	disk->inner_radius = dict_def_double(value, "inner_radius", 0.0);
	disk->outer_radius = dict_def_double(value, "outer_radius", 0.0);
	return (true);
}
