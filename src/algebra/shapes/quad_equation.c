/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   quad_equation.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: pacovali <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/12 18:56:23 by pacovali       #+#    #+#                */
/*   Updated: 2019/11/07 18:48:17 by nmartins      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "shape.h"

t_point2	quad_eq(REAL discr, REAL a, REAL b)
{
	REAL		square_root;
	REAL		result[2];
	t_point2	roots;

	roots.x = -1.0;
	roots.y = -1.0;
	square_root = sqrt(discr);
	result[0] = (-b - square_root) / (2.0 * a);
	result[1] = (-b + square_root) / (2.0 * a);
	if (result[0] > 0)
	{
		roots.x = result[0];
		roots.y = result[1];
		return (roots);
	}
	if (result[1] > 0)
		roots.x = result[1];
	return (roots);
}
