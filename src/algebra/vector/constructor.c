/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   constructor.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/26 18:57:11 by nmartins       #+#    #+#                */
/*   Updated: 2019/10/26 18:58:09 by nmartins      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

t_vec	vec_mk(REAL x, REAL y, REAL z)
{
	return ((t_vec){x, y, z});
}

t_vec	vec_make0(void)
{
	t_vec	v;

	v.x = 0;
	v.y = 0;
	v.z = 0;
	return (v);
}

t_vec	vec_make1(void)
{
	t_vec	v;

	v.x = 0;
	v.y = 0;
	v.z = 1;
	return (v);
}
