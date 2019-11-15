/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   intersect.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/15 18:40:28 by nmartins       #+#    #+#                */
/*   Updated: 2019/11/15 19:02:32 by nmartins      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>

#include "bbox.h"

bool			bbox_intersect(
	const t_bbox *box, const t_ray *ray, t_intersection *isect)
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
	sign = (t_vec){ray->d.x > 0 ? 1 : 0,
		ray->d.y > 0 ? 1 : 0, ray->d.z > 0 ? 1 : 0};
}


/*

        let inv_dir = Vec3::new(
            1.0 / ray.direction.x,
            1.0 / ray.direction.y,
            1.0 / ray.direction.z,
        );
        let sign = Vec3::new(
            if ray.direction.x > 0.0 { 1.0 } else { 0.0 },
            if ray.direction.y > 0.0 { 1.0 } else { 0.0 },
            if ray.direction.z > 0.0 { 1.0 } else { 0.0 },
        );

        let mut tmin = (self.bounds(sign.x).x - ray.origin.x) * inv_dir.x;
        let mut tmax = (self.bounds(1.0 - sign.x).x - ray.origin.x) * inv_dir.x;
        let tymin = (self.bounds(sign.y).y - ray.origin.y) * inv_dir.y;
        let tymax = (self.bounds(1.0 - sign.y).y - ray.origin.y) * inv_dir.y;

        if (tmin > tymax) || (tymin > tmax) {
            return false;
        }

        if tymin > tmin {
            tmin = tymin;
        }
        if tymax < tmax {
            tmax = tymax;
        }

        let tzmin = (self.bounds(sign.z).z - ray.origin.z) * inv_dir.z;
        let tzmax = (self.bounds(1.0 - sign.z).z - ray.origin.z) * inv_dir.z;

        if (tmin > tzmax) || (tzmin > tmax) {
            return false;
        }

        if tzmin > tmin {
            tmin = tzmin;
        }
        if tzmax < tmax {
            tmax = tzmax;
        }

        tmin >= 0.0 || tmax >= 0.0


 */
