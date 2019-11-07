/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cross.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: pacovali <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/12 18:56:23 by pacovali       #+#    #+#                */
/*   Updated: 2019/11/07 18:11:41 by nmartins      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

t_vec	vec_cross(const t_vec *a, const t_vec *b)
{
	t_vec	v;

	v.x = a->y * b->z - a->z * b->y;
	v.y = a->z * b->x - a->x * b->z;
	v.z = a->x * b->y - a->y * b->x;
	return (v);
}

t_vec	vec_cross_s(t_vec a, t_vec b)
{
	return (vec_cross(&a, &b));
}
