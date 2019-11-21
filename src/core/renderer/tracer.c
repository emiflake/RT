/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   tracer.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/07 16:35:34 by nmartins       #+#    #+#                */
/*   Updated: 2019/11/21 18:12:40 by nmartins      ########   odam.nl         */
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
#include "core/object/object.h"
#include "core/object/material.h"

void	reflected_clr(t_vec *color, REAL reflect)
{
	REAL	max;

	max = (color->x > color->y) ? color->x : color->y;
	max = (max > color->z) ? max : color->z;
	color->x += ((max - color->x) * reflect);
	color->y += ((max - color->y) * reflect);
	color->z += ((max - color->z) * reflect);
}

void	ray_calculate(const t_ray *ray, t_intersection *isect, t_ray *new_ray)
{
	if (float_rand() < isect->obj_ptr->material.transparent)
		refract(new_ray, (t_ray*)ray, isect);
	else if (float_rand() < isect->obj_ptr->material.blurriness)
		diffuse(&new_ray->d, &isect->normal, isect);
	else
		reflect(&new_ray->d, ray, isect);
	vec_normalize(&new_ray->d);
	new_ray->o = isect->p;
	new_ray->depth = ray->depth - 1;
}

t_vec	trace(const t_scene *scene, const t_ray *ray,
	t_intersection *isect, t_textures *tex)
{
	t_vec					aggregate_color;
	t_vec					hemi;
	t_ray					new_ray;
	t_intersection			new_isect;
	t_vec					current_color;

	intersection(&isect->obj_ptr->shape, ray, isect);
	aggregate_color = vec_make0();
	current_color = get_emission(isect, &isect->obj_ptr->material, tex);
	vec_add_mut(&aggregate_color, &current_color);
	if (ray->depth > 0)
	{
		ray_calculate(ray, isect, &new_ray);
		new_isect.t = INFINITY;
		if (bvh_is_intersect(scene->bvh, &new_ray, &new_isect))
		{
			hemi = trace(scene, &new_ray, &new_isect, tex);
			current_color = vec_mults_scalar(
				get_color(isect, &isect->obj_ptr->material, tex), 1.0 / 255.0);
			reflected_clr(&current_color, isect->obj_ptr->material.reflective);
			vec_mult_mut(&hemi, &current_color);
			vec_add_mut(&aggregate_color, &hemi);
		}
	}
	return (aggregate_color);
}
