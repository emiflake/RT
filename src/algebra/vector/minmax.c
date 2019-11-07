/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   minmax.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/05 16:17:16 by nmartins       #+#    #+#                */
/*   Updated: 2019/11/05 16:27:30 by nmartins      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"
#include "../mmath/mmath.h"

t_vec			vec_max(const t_vec *a, const t_vec *b)
{
	return ((t_vec){max(a->x, b->x), max(a->y, b->y), max(a->z, b->z)});
}

t_vec			vec_min(const t_vec *a, const t_vec *b)
{
	return ((t_vec){min(a->x, b->x), min(a->y, b->y), min(a->z, b->z)});
}
