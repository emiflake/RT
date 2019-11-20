/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   vec_rotate.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: pacovali <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/12 18:56:23 by pacovali       #+#    #+#                */
/*   Updated: 2019/11/15 14:53:24 by nmartins      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

/*
** rotate in global coordinates
*/

void			vec_rotate_xyz(t_vec *v, const t_vec *rotation_rad)
{
	if (rotation_rad->x)
		vec_rotate_one(v, rotation_rad->x, 1);
	if (rotation_rad->y)
		vec_rotate_one(v, rotation_rad->y, 2);
	if (rotation_rad->z)
		vec_rotate_one(v, rotation_rad->z, 3);
}

/*
** rotate in local (object's) coordinates - mostly for camera
*/

void			vec_rotate_zyx(t_vec *v, const t_vec *rotation_rad)
{
	if (rotation_rad->z)
		vec_rotate_one(v, rotation_rad->z, 3);
	if (rotation_rad->y)
		vec_rotate_one(v, rotation_rad->y, 2);
	if (rotation_rad->x)
		vec_rotate_one(v, rotation_rad->x, 1);
}
