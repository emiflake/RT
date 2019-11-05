/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   vec_cross.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: pacovali <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/12 18:56:23 by pacovali      #+#    #+#                 */
/*   Updated: 2019/01/23 17:53:36 by pacovali      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

t_vec	vec_cross(t_vec *a, t_vec *b)
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
