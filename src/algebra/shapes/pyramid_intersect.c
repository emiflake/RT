/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pyramid_intersect.c                                          :+:    :+:  */
/*                                                     +:+                    */
/*   By: pacovali <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/01 00:42:00 by pacovali      #+#    #+#                 */
/*   Updated: 2019/01/01 00:42:01 by pacovali      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "shape.h"

void	pyramid_intersection(const t_ray *ray, t_intersection *intrs)
{
	(void)ray;
	(void)intrs;
}

bool	is_pyramid_intersect(const t_shape *shape, const t_ray *ray,
							t_intersection *intrs)
{
	int				i;
	t_shape			shape2;
	bool			found;
	
	found = false;
	i = 0;
	while (i < 4)
	{
		shape2.val.as_triangle = (t_triangle)shape->val.as_pyramid.side[i];
		if (is_triangle_intersect(&shape2, ray, intrs))
			found = true;
		i++;
	}
	shape2.val.as_square = (t_square)shape->val.as_pyramid.base;
	if (is_square_intersect(&shape2, ray, intrs))
		found = true;
	return (found);
}
