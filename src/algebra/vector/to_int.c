/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   to_int.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/07 17:32:42 by nmartins       #+#    #+#                */
/*   Updated: 2019/11/07 17:34:03 by nmartins      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

int	vec_to_int(const t_vec *v)
{
	return ((int)v->x << 16 | (int)v->y << 8 | (int)v->z);
}

int	vec_to_ints(const t_vec v)
{
	return (vec_to_int(&v));
}
