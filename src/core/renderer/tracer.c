/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   tracer.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/07 16:35:34 by nmartins       #+#    #+#                */
/*   Updated: 2019/11/19 14:38:21 by jandre-d      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <ft_printf.h>
#include <pthread.h>
#include <unistd.h>

#include "threadpool/threadpool.h"
#include "algebra/mmath/mmath.h"
#include "renderer.h"
#include "perlin_noise/perlin_noise.h"
#include "ui/ui.h"

t_perlin_noise *perl;


t_vec		trace(const t_scene *scene, const t_ray *ray, t_intersection *isect)
{
	t_coordinate_system		sys;
	t_vec					aggregate_color;
	t_ray					new_ray;
	t_intersection			new_isect;

	intersection(&isect->obj_ptr->shape, ray, isect);
	aggregate_color = vec_make0();
	//vec_add_mut(&aggregate_color, &isect->obj_ptr->material.emission);

	float width =.4;

	perl = perlin_noise_init(20, 12);
	float value = perlin_noise(perl, isect->normal.x, isect->normal.y, .1);

	// if (
	// sin(M_PI * (isect->p.x) / width) > 0 && 
	// sin(M_PI * (isect->p.y) / width) > 0)
	// {
	// 	aggregate_color.x = 255;
	// }


	if (
	sin(M_PI * value * 200 / width) > 0)
	{
		aggregate_color.x = 255;
	}
	else
	{
		aggregate_color.z = 255;
	}


	// hemi.x= ((float)255 * value);
	// hemi.y = ((float)255 * value);
	// hemi.z= ((float)255 * value);

	return (aggregate_color);
}
