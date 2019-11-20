/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   move.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: pacovali <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/12 18:56:23 by pacovali       #+#    #+#                */
/*   Updated: 2019/11/07 17:14:56 by nmartins      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

#include "shape.h"

bool	move_shape(t_shape *shape, t_vec *direction, REAL amount)
{
	static t_move_fn	fns[] = {
		&sphere_move, &plane_move, &disk_move,
		&square_move, &triangle_move, &cylinder_move,
		&cone_move, &cube_move, &pyramid_move, &tetrahedron_move
	};

	vec_normalize(direction);
	return (fns[shape->type](shape, direction, amount));
}
