/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   camera.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/26 16:32:43 by nmartins       #+#    #+#                */
/*   Updated: 2019/11/20 17:19:17 by nmartins      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>
#include <assert.h>

#include "./algebra/shapes/shape.h"
#include "./common/common.h"
#include "./algebra/vector/vector.h"
#include "./json/json.h"
#include "algebra/mmath/mmath.h"

#include "./ui/ui.h"
#include "core/camera/camera.h"
#include "core/object/object.h"

void			camera_recompute(t_camera *camera, size_t w, size_t h)
{
	camera->delta = tan(camera->fov / 2.0 * M_PI / 180.0);
	camera->aspect_ratio = (REAL)w / (REAL)h;
	camera->dim.x = w;
	camera->dim.y = h;
}

static t_point2	supersample(REAL delta)
{
	t_point2	super_pixel;

	super_pixel.x = delta * float_rand() * 2.0 - 1.0;
	super_pixel.y = delta * float_rand() * 2.0 - 1.0;
	return (super_pixel);
}

void			camera_cast_ray(
		const t_camera *cam, const t_point2 *pos, t_ray *ray_out)
{
	REAL		px;
	REAL		py;
	t_vec		dir;
	t_point2	super;

	super = supersample(cam->delta);
	px = (2.0 * (((REAL)pos->x + 0.5 + super.x) / cam->dim.x) - 1.0)
		* cam->aspect_ratio * cam->delta;
	py = (1.0 - 2.0 * ((REAL)pos->y + 0.5 + super.y) / cam->dim.y) * cam->delta;
	dir = vec_mk(px, py, 1.0);
	vec_normalize(&dir);
	vec_rotate_xyz(&dir, &cam->rotation);
	ray_out->o = cam->origin;
	ray_out->d = dir;
	ray_out->depth = cam->recursion;
}
