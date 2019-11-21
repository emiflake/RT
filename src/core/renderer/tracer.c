/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   tracer.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/07 16:35:34 by nmartins       #+#    #+#                */
/*   Updated: 2019/11/21 17:01:43 by nmartins      ########   odam.nl         */
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

void	diffuse(t_vec *dir, t_vec *vector, t_intersection *isect)
{
	t_coordinate_system		sys;
	t_vec					hemi;

	coord_system_create(&isect->normal, &sys);
	hemi = hemisphere(float_rand(), float_rand());
	*dir = (t_vec){
	hemi.x * sys.nb.x + hemi.y * vector->x + hemi.z * sys.nt.x,
	hemi.x * sys.nb.y + hemi.y * vector->y + hemi.z * sys.nt.y,
	hemi.x * sys.nb.z + hemi.y * vector->z + hemi.z * sys.nt.z};
}

void	reflect(t_vec *dir, const t_ray *ray, t_intersection *isect)
{
	*dir = vec_reflect((t_vec*)&ray->d, &isect->normal);
	*dir = vec_adds(*dir,
	(t_vec){float_rand() * isect->obj_ptr->material.blurriness,
			float_rand() * isect->obj_ptr->material.blurriness,
			float_rand() * isect->obj_ptr->material.blurriness});
}

bool	check_reflectance(t_ray *new_ray, t_ray *ray, t_intersection *isect)
{
	REAL	reflectance;

	if (ray->cur_obj)
		reflectance = vec_reflectance(&ray->d, &isect->normal, ray->refration,
									INIT_MEDIA);
	else
		reflectance = vec_reflectance(&ray->d, &isect->normal, INIT_MEDIA,
									isect->obj_ptr->material.refraction);
	if (float_rand() > reflectance)
		return (true);
	if (float_rand() < isect->obj_ptr->material.blurriness)
		diffuse(&new_ray->d, &isect->normal, isect);
	else
		reflect(&new_ray->d, ray, isect);
	return (false);
}

void	refract(t_ray *new_ray, t_ray *ray, t_intersection *isect)
{
	t_vec		norm;

	if (!check_reflectance(new_ray, ray, isect))
		return ;
	norm = vec_negate(&isect->normal);
	if (ray->cur_obj == NULL || ray->cur_obj != isect->obj_ptr)
	{
		new_ray->d = vec_refracts(ray->d, norm, INIT_MEDIA,
							isect->obj_ptr->material.refraction);
		new_ray->cur_obj = isect->obj_ptr;
		new_ray->refration = isect->obj_ptr->material.refraction;
	}
	else if (ray->cur_obj == isect->obj_ptr)
	{
		new_ray->d = vec_refracts(ray->d, norm, ray->refration, INIT_MEDIA);
		new_ray->cur_obj = NULL;
	}
	new_ray->d = vec_adds(new_ray->d,
	(t_vec){float_rand() * isect->obj_ptr->material.blurriness,
			float_rand() * isect->obj_ptr->material.blurriness,
			float_rand() * isect->obj_ptr->material.blurriness});
}

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
	if (!isect->obj_ptr->material.is_parallel)
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
