/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pyramid_move.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: pacovali <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/01 00:42:00 by pacovali      #+#    #+#                 */
/*   Updated: 2019/01/01 00:42:01 by pacovali      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "shape.h"

bool	pyramid_move(t_shape *shape, t_vec *direction, REAL distance)
{
	int		i;

	vec_mult_mut_scalar(direction, distance);
	vec_add_mut(&shape->val.as_pyramid.origin, direction);
	i = 0;
	while (i < 4)
	{
		vec_add_mut(&shape->val.as_pyramid.side[i].plane.origin, direction);
		vec_add_mut(&shape->val.as_pyramid.side[i].point_b, direction);
		vec_add_mut(&shape->val.as_pyramid.side[i].point_c, direction);
		i++;
	}
	vec_add_mut(&shape->val.as_pyramid.base.plane.origin, direction);
	return (true);
}
