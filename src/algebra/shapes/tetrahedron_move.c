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
	int		i;

	vec_mult_mut_scalar(direction, distance);
	vec_add_mut(&shape->val.as_tetrahedron.origin, direction);
	i = 0;
	while (i < 4)
	{
		vec_add_mut(&shape->val.as_tetrahedron.side[i].plane.origin, direction);
		vec_add_mut(&shape->val.as_tetrahedron.side[i].point_b, direction);
		vec_add_mut(&shape->val.as_tetrahedron.side[i].point_c, direction);
		i++;
	}
	return (true);
}
