/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   vector_randomizer.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/07 18:02:24 by nmartins       #+#    #+#                */
/*   Updated: 2019/11/07 18:03:29 by nmartins      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <stdlib.h>

#include "mmath.h"

void	coord_system_create(const t_vec *n, t_coordinate_system *coord)
{
	t_vec	nt;

	if (fabs(n->x) > fabs(n->y))
		nt = vec_mults_scalar(vec_mk(n->z, 0.0, -n->x),
			1.0 / sqrt(n->x * n->x + n->z * n->z));
	else
		nt = vec_mults_scalar(vec_mk(0.0, -n->z, n->y),
			1.0 / sqrt(n->y * n->y + n->z * n->z));
	coord->nt = nt;
	coord->nb = vec_cross(n, &nt);
}

t_vec	hemisphere(REAL u, REAL v)
{
	double sin_theta;
	double phi;

	sin_theta = sqrt(1.0 - u * u);
	phi = 2.0 * M_PI * v;
	return (vec_mk(cos(phi) * sin_theta, u, sin(phi) * sin_theta));
}
