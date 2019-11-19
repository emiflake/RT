/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   triangle_rotate.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: pacovali <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/01 00:42:00 by pacovali      #+#    #+#                 */
/*   Updated: 2019/01/01 00:42:01 by pacovali      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "shape.h"

bool	triangle_rotate(t_shape *shape, t_vec *rotation_rad)
{
	t_triangle	*tri;
	REAL		len;
	int			i;

	tri = &shape->val.as_triangle;
	vec_rotate_xyz(&tri->normal[0], rotation_rad);
	i = 0;
	while (i < 1)
	{
		len = sqrt(vec_dot(&tri->side[i], &tri->side[i]));
		vec_normalize(&tri->side[i]);
		vec_rotate_xyz(&tri->side[i], rotation_rad);
		vec_mult_mut_scalar(&tri->side[i], len);
		tri->point[i + 1] = vec_add(&tri->point[0], &tri->side[i]);
		vec_rotate_xyz(&tri->normal[i + 1], rotation_rad);
		i++;
	}
	return (true);
}
