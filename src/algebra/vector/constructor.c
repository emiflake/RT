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

t_vec	vec_make1(REAL r)
{
	return ((t_vec){r, r, r});
}

t_vec	vec_mk(REAL x, REAL y, REAL z)
{
	return ((t_vec){x, y, z});
}
