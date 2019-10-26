/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   subtraction.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/26 19:30:46 by nmartins       #+#    #+#                */
/*   Updated: 2019/10/26 19:40:44 by nmartins      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

t_vec	vec_subs(const t_vec a, const t_vec b)
{
	return ((t_vec){a.x - b.x, a.y - b.y, a.z - b.z});
}

t_vec	vec_sub(const t_vec *a, const t_vec *b)
{
	return ((t_vec){a->x - b->x, a->y - b->y, a->z - b->z});
}

void	vec_sub_mut(t_vec *a, const t_vec *b)
{
	a->x -= b->x;
	a->y -= b->y;
	a->z -= b->z;
}
