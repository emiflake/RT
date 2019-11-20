/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   square_rotate.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: pacovali <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/01 00:42:00 by pacovali      #+#    #+#                 */
/*   Updated: 2019/01/01 00:42:01 by pacovali      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "shape.h"

bool	square_rotate(t_shape *shape, t_vec *rotation_rad)
{
	t_square	*square;

	square = &shape->val.as_square;
	vec_rotate_xyz(&square->plane.normal, rotation_rad);
	vec_normalize(&square->side_a);
	vec_rotate_xyz(&square->side_a, rotation_rad);
	vec_mult_mut_scalar(&square->side_a, sqrt(square->dot_a));
	vec_normalize(&square->side_b);
	vec_rotate_xyz(&square->side_b, rotation_rad);
	vec_mult_mut_scalar(&square->side_b, sqrt(square->dot_b));
	return (true);
}
