/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   addition.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/26 18:53:54 by nmartins       #+#    #+#                */
/*   Updated: 2019/10/26 19:40:52 by nmartins      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

t_vec	vec_adds(const t_vec a, const t_vec b)
{
	return ((t_vec){a.x + b.x, a.y + b.y, a.z + b.z});
}

t_vec	vec_add(const t_vec *a, const t_vec *b)
{
	return ((t_vec){a->x + b->x, a->y + b->y, a->z + b->z});
}

void	vec_add_mut(t_vec *a, const t_vec *b)
{
	a->x += b->x;
	a->y += b->y;
	a->z += b->z;
}
