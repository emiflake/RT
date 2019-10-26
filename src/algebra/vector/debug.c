/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   debug.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/26 19:00:18 by nmartins       #+#    #+#                */
/*   Updated: 2019/10/26 19:47:55 by nmartins      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

#include "vector.h"

void	vec_debug(const t_vec *v)
{
	ft_printf("%f, %f, %f", v->x, v->y, v->z);
}

void	vec_debugs(const t_vec v)
{
	vec_debug(&v);
}
