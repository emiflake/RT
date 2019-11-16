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

bool			bbox_intersect(
	const t_bbox *box, const t_ray *ray)
{
	t_vec	inv_dir;
	t_vec	sign;
	REAL	tmin;
	REAL	tmax;
	REAL	tymin;
	REAL	tymax;
	REAL	tzmin;
	REAL	tzmax;

	inv_dir = (t_vec){1.0 / ray->d.x, 1.0 / ray->d.y, 1.0 / ray->d.z};
	sign = (t_vec){ray->d.x < 0.0 ? true : false,
		ray->d.y < 0.0 ? true : false, ray->d.z < 0.0 ? true : false};
	tmin = (bbox_bounds(box, sign.x).x - ray->o.x) * inv_dir.x;
	tmax = (bbox_bounds(box, 1.0 - sign.x).x - ray->o.x) * inv_dir.x;
	tymin = (bbox_bounds(box, sign.y).y - ray->o.y) *inv_dir.y;
	tymax = (bbox_bounds(box, 1.0 - sign.y).y - ray->o.y) *inv_dir.y;
	// printf("%lf %l?f ; %lf %lf\n", tmin, tmax, tymin, tymax);

	/*
        let mut tmin = (self.bounds(ray.sign.x).x - ray.origin.x) * ray.inv_dir.x;
        let mut tmax = (self.bounds(1.0 - ray.sign.x).x - ray.origin.x) * ray.inv_dir.x;
        let tymin = (self.bounds(ray.sign.y).y - ray.origin.y) * ray.inv_dir.y;
        let tymax = (self.bounds(1.0 - ray.sign.y).y - ray.origin.y) * ray.inv_dir.y;

	*/
	if (tmin > tymax || tymin > tmax)
		return (false);
	if (tymin > tmin)
		tmin = tymin;
	if (tymax < tmax)
		tmax = tymax;
	tzmin = (bbox_bounds(box, sign.z).z - ray->o.z) *inv_dir.z;
	tzmax = (bbox_bounds(box, 1.0 - sign.z).z - ray->o.z) *inv_dir.z;
	if (tmin > tzmax || tzmin > tmax)
		return (false);
	if (tzmin > tmin)
		tmin = tzmin;
	if (tzmax < tmax)
		tmax = tzmax;
	return (tmin >= 0.0 || tmax >= 0.0);
}
