/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   tracer_utils.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/21 18:12:27 by nmartins       #+#    #+#                */
/*   Updated: 2019/11/21 18:14:06 by nmartins      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

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
