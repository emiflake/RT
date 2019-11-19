/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   disk_rotate.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: pacovali <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/01 00:42:00 by pacovali      #+#    #+#                 */
/*   Updated: 2019/01/01 00:42:01 by pacovali      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "shape.h"

bool	disk_rotate(t_shape *shape, t_vec *rotation_rad)
{
	vec_rotate_xyz(&shape->val.as_disk.plane.normal, rotation_rad);
	return (true);
}
