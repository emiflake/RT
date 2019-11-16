/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   tracer.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/07 16:35:34 by nmartins       #+#    #+#                */
/*   Updated: 2019/11/15 23:48:59 by nmartins      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <ft_printf.h>
#include <pthread.h>
#include <unistd.h>

#include "threadpool/threadpool.h"
#include "algebra/mmath/mmath.h"
#include "renderer.h"
#include "ui/ui.h"

t_vec		trace(const t_scene *scene, const t_ray *ray, t_intersection *isect)
{
	t_coordinate_system		sys;
	t_vec					aggregate_color;
	t_vec					hemi;
	t_ray					new_ray;
	t_intersection			new_isect;

	intersection(&isect->obj_ptr->shape, ray, isect);
	aggregate_color = vec_make0();
	vec_add_mut(&aggregate_color, &isect->obj_ptr->material.emission);
	if (ray->depth > 0)
	{
		coord_system_create(&isect->normal, &sys);
		hemi = hemisphere(float_rand(), float_rand());
		new_ray.d = vec_mk(
			hemi.x * sys.nb.x + hemi.y * isect->normal.x + hemi.z * sys.nt.x,
			hemi.x * sys.nb.y + hemi.y * isect->normal.y + hemi.z * sys.nt.y,
			hemi.x * sys.nb.z + hemi.y * isect->normal.z + hemi.z * sys.nt.z);
		new_ray.o = isect->p;
		new_ray.depth = ray->depth - 1;
		new_isect.t = INFINITY;
		if (bvh_is_intersect(scene->bvh, &new_ray, &new_isect))
		{
			hemi = trace(scene, &new_ray, &new_isect);
			t_vec temp = vec_mults_scalar(isect->obj_ptr->material.color, 1.0 / 255.0);
			vec_mult_mut(&hemi, &temp);
			vec_add_mut(&aggregate_color, &hemi);
		}
	}
	return (aggregate_color);
}
