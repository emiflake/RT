/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   intersect.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/15 18:40:28 by nmartins       #+#    #+#                */
/*   Updated: 2019/11/15 23:26:26 by nmartins      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <stdio.h>
#include <ft_printf.h>

#include "bbox.h"

#include <unistd.h>

bool	bbox_intersect(const t_bbox *box, const t_ray *ray)
{
	t_vec	inv_dir;
	t_vec	sign;
	t_vec	tmin;
	t_vec	tmax;

	inv_dir = (t_vec){1.0 / ray->d.x, 1.0 / ray->d.y, 1.0 / ray->d.z};
	sign = (t_vec){ray->d.x < 0.0 ? true : false,
		ray->d.y < 0.0 ? true : false, ray->d.z < 0.0 ? true : false};
	tmin.x = (bbox_bounds(box, sign.x).x - ray->o.x) * inv_dir.x;
	tmax.x = (bbox_bounds(box, 1.0 - sign.x).x - ray->o.x) * inv_dir.x;
	tmin.y = (bbox_bounds(box, sign.y).y - ray->o.y) * inv_dir.y;
	tmax.y = (bbox_bounds(box, 1.0 - sign.y).y - ray->o.y) * inv_dir.y;
	if (tmin.x > tmax.y || tmin.y > tmax.x)
		return (false);
	if (tmin.y > tmin.x)
		tmin.x = tmin.y;
	if (tmax.y < tmax.x)
		tmax.x = tmax.y;
	tmin.z = (bbox_bounds(box, sign.z).z - ray->o.z) * inv_dir.z;
	tmax.z = (bbox_bounds(box, 1.0 - sign.z).z - ray->o.z) * inv_dir.z;
	if (tmin.x > tmax.z || tmin.z > tmax.x)
		return (false);
	tmin.x = (tmin.z > tmin.x) ? tmin.z : tmin.x;
	tmax.x = (tmax.z < tmax.x) ? tmax.z : tmax.x;
	return (tmin.x >= 0.0 || tmax.x >= 0.0);
}
