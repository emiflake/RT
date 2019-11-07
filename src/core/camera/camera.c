/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/26 16:32:43 by nmartins       #+#    #+#                */
/*   Updated: 2019/11/07 14:37:56 by pacovali      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>
#include <assert.h>

#include "./algebra/shapes/shape.h"
#include "./common/common.h"
#include "./algebra/vector/vector.h"
#include "./json/json.h"

#include "./ui/ui.h"
#include "core/camera/camera.h"
#include "core/object/object.h"


void			camera_recompute(t_camera *camera, const t_point2 *dim)
{
	camera->delta = tan(camera->fov / 2.0 * M_PI / 180.0);
	camera->aspect_ratio = dim->x / dim->y;
}

void			camera_cast_ray(
		const t_camera *cam, const t_point2 *pos, const t_point2 *dim, t_ray *ray_out)
{
	REAL	px;
	REAL	py;
	t_vec	dir;
	
	px = (2.0 * (((REAL)pos->x + 0.5) / dim->x) - 1.0)
		* cam->aspect_ratio * cam->delta;
	py = (1.0 - 2.0 * ((REAL)pos->y + 0.5) / dim->y) * cam->delta;
	dir = vec_mk(px, py, 1.0);
	vec_normalize(&dir);
	ray_out->o = cam->origin;
	ray_out->d = dir;
	ray_out->depth = 5;
}
