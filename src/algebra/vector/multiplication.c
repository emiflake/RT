/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   multiplication.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/28 14:09:27 by nmartins       #+#    #+#                */
/*   Updated: 2019/10/28 14:20:07 by nmartins      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

t_vec			vec_mults(const t_vec a, const t_vec b)
{
	return ((t_vec){a.x * b.x, a.y * b.y, a.z * b.z});
}

t_vec			vec_mult(const t_vec *a, const t_vec *b)
{
	return ((t_vec){a->x * b->x, a->y * b->y, a->z * b->z});
}

void			vec_mult_mut(t_vec *a, const t_vec *b)
{
	a->x *= b->x;
	a->y *= b->y;
	a->z *= b->z;
}

t_vec			vec_mults_scalar(const t_vec a, REAL scalar)
{
	return ((t_vec){ a.x * scalar, a.y * scalar, a.z * scalar });
}

void			vec_mult_mut_scalar(t_vec *a, REAL scalar)
{
	a->x *= scalar;
	a->y *= scalar;
	a->z *= scalar;
}
