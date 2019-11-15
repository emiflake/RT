/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   vec_rotate.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: pacovali <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/12 18:56:23 by pacovali       #+#    #+#                */
/*   Updated: 2019/11/15 14:53:24 by nmartins      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

/*
** angles must be converted to rads before passing into the functions
*/

static void		axis_x(t_vec *v, t_vec *r, REAL cos_angle, REAL sin_angle)
{
	r->y = v->y * cos_angle - v->z * sin_angle;
	r->z = v->y * sin_angle + v->z * cos_angle;
	vec_normalize(r);
}

static void		axis_y(t_vec *v, t_vec *r, REAL cos_angle, REAL sin_angle)
{
	r->x = v->x * cos_angle - v->z * sin_angle;
	r->z = v->x * sin_angle + v->z * cos_angle;
	vec_normalize(r);
}

static void		axis_z(t_vec *v, t_vec *r, REAL cos_angle, REAL sin_angle)
{
	r->x = v->x * cos_angle - v->y * sin_angle;
	r->y = v->x * sin_angle + v->y * cos_angle;
	vec_normalize(r);
}

/*
** rotate in around one axis (axis_id: 1 - x-axis, 2 - y-axis, 3 - z-axis)
*/

void			vec_rotate_one(t_vec *v, REAL angle_rad, int axis_id)
{
	t_vec	r;
	REAL	cos_angle;
	REAL	sin_angle;

	r = *v;
	cos_angle = cos(angle_rad);
	sin_angle = sin(angle_rad);
	if (axis_id == 1)
		axis_x(v, &r, cos_angle, sin_angle);
	else if (axis_id == 2)
		axis_y(v, &r, cos_angle, sin_angle);
	else if (axis_id == 3)
		axis_z(v, &r, cos_angle, sin_angle);
	*v = r;
}

/*
** rotate in global coordinates
*/

void			vec_rotate_xyz(t_vec *v, const t_vec *rotation_rad)
{
	if (rotation_rad->x)
		vec_rotate_one(v, rotation_rad->x, 1);
	if (rotation_rad->y)
		vec_rotate_one(v, rotation_rad->y, 2);
	if (rotation_rad->z)
		vec_rotate_one(v, rotation_rad->z, 3);
}

/*
** rotate in local (object's) coordinates - mostly for camera
*/

void			vec_rotate_zyx(t_vec *v, const t_vec *rotation_rad)
{
	if (rotation_rad->z)
		vec_rotate_one(v, rotation_rad->z, 3);
	if (rotation_rad->y)
		vec_rotate_one(v, rotation_rad->y, 2);
	if (rotation_rad->x)
		vec_rotate_one(v, rotation_rad->x, 1);
}
