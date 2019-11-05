/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   vec_angle.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: pacovali <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/12 18:56:23 by pacovali      #+#    #+#                 */
/*   Updated: 2019/01/23 17:53:36 by pacovali      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

REAL	vec_angle_rad(t_vec *a, t_vec *b)
{
	return (acos(vec_dot(a, b) / vec_dot(a, a)));
}

REAL	vec_angle_rads(t_vec a, t_vec b)
{
	return (vec_angle_rad(&a, &b));
}

REAL	vec_angle_deg(t_vec *a, t_vec *b)
{
	return (rad_to_deg(vec_angle_rad(a, b)));
}

REAL	vec_angle_degs(t_vec a, t_vec b)
{
	return (vec_angle_deg(&a, &b));
}
