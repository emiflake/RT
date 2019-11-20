/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cube_intersect.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: pacovali <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/01 00:42:00 by pacovali       #+#    #+#                */
/*   Updated: 2019/11/12 18:38:35 by nmartins      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "shape.h"

void	cube_intersection(const t_ray *ray, t_intersection *intrs)
{
	(void)ray;
	(void)intrs;
}

bool	is_cube_intersect(const t_shape *shape, const t_ray *ray,
							t_intersection *intrs)
{
	int				i;
	t_shape			shape2;
	bool			found;

	found = false;
	i = 0;
	while (i < 6)
	{
		shape2.val.as_square = shape->val.as_cube.side[i];
		if (is_square_intersect(&shape2, ray, intrs))
			found = true;
		i++;
	}
	return (found);
}
