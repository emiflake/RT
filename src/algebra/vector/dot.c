/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   dot.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/26 19:32:36 by nmartins       #+#    #+#                */
/*   Updated: 2019/11/18 10:17:08 by nmartins      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

REAL	vec_dot(const t_vec *a, const t_vec *b)
{
	return (a->x * b->x + a->y * b->y + a->z * b->z);
}
