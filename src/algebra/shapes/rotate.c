/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rotate.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: pacovali <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/12 18:56:23 by pacovali       #+#    #+#                */
/*   Updated: 2019/11/07 17:14:56 by nmartins      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

#include "shape.h"

bool	rotate_shape(t_shape *shape, t_vec *rotation_rad)
{
	t_rotate_fn	fns[] = {
		&sphere_rotate, &plane_rotate, &disk_rotate,
		&square_rotate, &triangle_rotate, &cylinder_rotate,
		&cone_rotate, &cube_rotate, &pyramid_rotate, &tetrahedron_rotate
	};
	return (fns[shape->type](shape, rotation_rad));
}
