/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pyramid_rotate.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: pacovali <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/01 00:42:00 by pacovali      #+#    #+#                 */
/*   Updated: 2019/01/01 00:42:01 by pacovali      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "shape.h"

bool	pyramid_rotate(t_shape *shape, t_vec *rotation_rad)
{
	t_pyramid	*pyr;
	t_vec		edge;
	int			i;
	REAL		len;

	pyr = &shape->val.as_pyramid;
	i = 0;
	while (i < 4)
	{
		edge = vec_sub(&pyr->point[i], &pyr->origin);
		len = sqrt(vec_dot(&edge, &edge));
		vec_normalize(&edge);
		vec_rotate_xyz(&edge, rotation_rad);
		vec_mult_mut_scalar(&edge, len);
		pyr->point[i] = vec_add(&pyr->origin, &edge);
		i++;
	}
	pyramid_set_sides(pyr);
	pyramid_normals(pyr);
	return (true);
}
