/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   length.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/26 19:38:15 by nmartins       #+#    #+#                */
/*   Updated: 2019/10/26 19:43:18 by nmartins      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

#include "vector.h"

double	vec_length2s(const t_vec a)
{
	return (vec_length2(&a));
}

double	vec_length2(const t_vec *a)
{
	return (a->x * a->x + a->y * a->y + a->z * a->z);
}

double	vec_lengths(const t_vec a)
{
	return (vec_length(&a));
}

double	vec_length(const t_vec *a)
{
	return (sqrt(vec_length2(a)));
}
