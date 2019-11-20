/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   tetrahedron_rotate.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: pacovali <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/01 00:42:00 by pacovali      #+#    #+#                 */
/*   Updated: 2019/01/01 00:42:01 by pacovali      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "shape.h"

bool	tetrahedron_rotate(t_shape *shape, t_vec *rotation_rad)
{
	t_tetrahedron	*tet;
	t_vec			edge;
	int				i;
	REAL			len;

	tet = &shape->val.as_tetrahedron;
	i = 1;
	while (i < 4)
	{
		edge = vec_sub(&tet->point[i], &tet->point[0]);
		len = sqrt(vec_dot(&edge, &edge));
		vec_normalize(&edge);
		vec_rotate_xyz(&edge, rotation_rad);
		vec_mult_mut_scalar(&edge, len);
		tet->point[i] = vec_add(&tet->point[0], &edge);
		i++;
	}
	tetrahedron_set_sides(tet);
	return (true);
}
