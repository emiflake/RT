/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   normalize.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/26 19:36:22 by nmartins       #+#    #+#                */
/*   Updated: 2019/10/26 19:42:22 by nmartins      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

t_vec	vec_normalizeds(const t_vec a)
{
	return (vec_normalized(&a));
}

t_vec	vec_normalized(const t_vec *a)
{
	REAL l;

	l = vec_length(a);
	return ((t_vec){a->x / l, a->y / l, a->z / l});
}

void	vec_normalize(t_vec *v)
{
	REAL l;

	l = vec_length(v);
	v->x /= l;
	v->y /= l;
	v->z /= l;
}
