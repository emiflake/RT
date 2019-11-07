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

#ifndef CAMERA_H
# define CAMERA_H

# include "algebra/point2/point2.h"
# include "algebra/vector/vector.h"
# include "algebra/ray/ray.h"

typedef struct	s_viewport
{
	REAL	width;
	REAL	height;
}				t_viewport;

typedef struct	s_camera
{
	t_vec		origin;
	t_vec		rotation;
	
	REAL		aspect_ratio;
	REAL		delta;
	
	REAL		fov;
}				t_camera;

void			camera_recompute(t_camera *camera, const t_point2 *dim);

void			camera_cast_ray(
	const t_camera *cam, const t_point2 *pos, const t_point2 *dim, t_ray *ray_out);

#endif
