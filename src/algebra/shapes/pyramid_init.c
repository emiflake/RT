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

void					pyramid_normals(t_pyramid *pyr)
{
	t_vec	test_vec;
	int		i;

	test_vec = vec_sub(&pyr->point[0], &pyr->origin);
	if (vec_dot(&pyr->base.plane.normal, &test_vec) < 0)
		vec_negate(&pyr->base.plane.normal);
	i = 0;
	while (i < 8)
	{
		test_vec = vec_sub(&pyr->point[i], &pyr->point[(i + 3) % 4]);
		if (vec_dot(&pyr->side[i].normal[0], &test_vec) < 0)
		{
			vec_negate(&pyr->side[i].normal[0]);
			vec_negate(&pyr->side[i].normal[1]);
			vec_negate(&pyr->side[i].normal[2]);
		}
		i++;
	}
}

bool					pyramid_init(
	t_shape *shape_out, const t_json_value *value)
{
	t_pyramid	*pyr;

	shape_out->type = SHAPE_PYRAMID;
	pyr = &shape_out->val.as_pyramid;
	dict_def_vec(value, "origin", (t_vec){0, 0, 0}, &pyr->origin);
	dict_def_vec(value, "a_pos", (t_vec){0, 0, 0}, &pyr->point[0]);
	dict_def_vec(value, "b_pos", (t_vec){0, 0, 0}, &pyr->point[1]);
	dict_def_vec(value, "c_pos", (t_vec){0, 0, 0}, &pyr->point[2]);
	dict_def_vec(value, "d_pos", (t_vec){0, 0, 0}, &pyr->point[3]);
	triangle_set(&pyr->side[0], pyr->point[0], pyr->origin, pyr->point[1]);
	triangle_set(&pyr->side[1], pyr->point[1], pyr->origin, pyr->point[2]);
	triangle_set(&pyr->side[2], pyr->point[2], pyr->origin, pyr->point[3]);
	triangle_set(&pyr->side[3], pyr->point[3], pyr->origin, pyr->point[0]);
	triangle_set(&pyr->side[4], pyr->point[1], pyr->origin, pyr->point[0]);
	triangle_set(&pyr->side[5], pyr->point[2], pyr->origin, pyr->point[1]);
	triangle_set(&pyr->side[6], pyr->point[3], pyr->origin, pyr->point[2]);
	triangle_set(&pyr->side[7], pyr->point[0], pyr->origin, pyr->point[3]);
	square_set(&pyr->base, pyr->point[1], pyr->point[0], pyr->point[2]);
	pyramid_normals(pyr);
	return (true);
}
