/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   tetrahedron_move.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: pacovali <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/01 00:42:00 by pacovali      #+#    #+#                 */
/*   Updated: 2019/01/01 00:42:01 by pacovali      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "shape.h"

bool	tetrahedron_move(t_shape *shape, t_vec *direction, REAL distance)
{
	t_tetrahedron	*tet;

	tet = &shape->val.as_tetrahedron;
	vec_mult_mut_scalar(direction, distance);
	vec_add_mut(&tet->point[0], direction);
	vec_add_mut(&tet->point[1], direction);
	vec_add_mut(&tet->point[2], direction);
	vec_add_mut(&tet->point[3], direction);
	triangle_set(&tet->side[0], tet->point[2], tet->point[3], tet->point[1]);
	triangle_set(&tet->side[1], tet->point[3], tet->point[0], tet->point[2]);
	triangle_set(&tet->side[2], tet->point[1], tet->point[0], tet->point[3]);
	triangle_set(&tet->side[3], tet->point[2], tet->point[0], tet->point[1]);
	triangle_set(&tet->side[4], tet->point[1], tet->point[3], tet->point[2]);
	triangle_set(&tet->side[5], tet->point[2], tet->point[0], tet->point[3]);
	triangle_set(&tet->side[6], tet->point[3], tet->point[0], tet->point[1]);
	triangle_set(&tet->side[7], tet->point[1], tet->point[0], tet->point[2]);
	return (true);
}
