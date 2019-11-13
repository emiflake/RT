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

bool					triangle_init(
	t_shape *shape_out, const t_json_value *value)
{
	t_triangle	*tri;

	shape_out->type = SHAPE_TRIANGLE;
	tri = &shape_out->val.as_triangle;
	(void)shape_out;
	(void)value;
	return (true);
}