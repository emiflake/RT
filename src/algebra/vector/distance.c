/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   distance.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/26 19:43:48 by nmartins       #+#    #+#                */
/*   Updated: 2019/11/18 10:17:38 by nmartins      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

REAL	vec_distances(const t_vec a, const t_vec b)
{
	const t_vec	delta = vec_sub(&b, &a);

	return (vec_length(&delta));
}

REAL	vec_distance(const t_vec *a, const t_vec *b)
{
	const t_vec	delta = vec_sub(b, a);

	return (vec_length(&delta));
}
