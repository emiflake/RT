/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   disk_move.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: pacovali <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/01 00:42:00 by pacovali      #+#    #+#                 */
/*   Updated: 2019/01/01 00:42:01 by pacovali      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "shape.h"

bool	disk_move(t_shape *shape, t_vec *direction, REAL distance)
{
	vec_mult_mut_scalar(direction, distance);
	vec_add_mut(&shape->val.as_disk.plane.origin, direction);
	return (true);
}
