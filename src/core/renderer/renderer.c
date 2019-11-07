/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   renderer.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/07 16:35:34 by nmartins       #+#    #+#                */
/*   Updated: 2019/11/07 19:22:21 by nmartins      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <ft_printf.h>

#include "algebra/mmath/mmath.h"
#include "renderer.h"
#include "ui/ui.h"

typedef struct	s_coordinate_system 
{
	t_vec	nt;
	t_vec	nb;
}				t_coordinate_system;

void	coord_system_create(const t_vec *n, t_coordinate_system *coord)
{
	t_vec	nt;

	if (fabs(n->x) > fabs(n->y))
		nt = vec_mults_scalar(vec_mk(n->z, 0.0, -n->x),
			1.0 / sqrt(n->x * n->x + n->z * n->z));
	else
		nt = vec_mults_scalar(vec_mk(0.0, -n->z, n->y),
			1.0 / sqrt(n->y * n->y + n->z * n->z));
	coord->nt = nt;
	coord->nb = vec_cross(n, &nt);
}

t_vec	hemisphere(REAL u, REAL v)
{
	double sin_theta;
	double phi;

	sin_theta = sqrt(1.0 - u * u);
	phi = 2.0 * M_PI * v;
	return (vec_mk(cos(phi) * sin_theta, u, sin(phi) * sin_theta));
}

t_vec		trace(const t_scene *scene, const t_ray *ray, t_intersection *isect)
{
	t_coordinate_system		sys;
	t_vec					aggregate_color;
	t_vec					hemi;
	t_ray					new_ray;
	t_intersection			new_isect;

	(void)scene;
	(void)ray;
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
		// new_ray.o = vec_adds(ray->o, vec_mults_scalar(isect->normal, EPS));
		new_ray.depth = ray->depth - 1;
		new_isect.t = INFINITY;
		// ft_printf("ro: %lf %lf %lf, rd: %lf %lf %lf, depth: %hhu\n", 
		// 	new_ray.o.x, new_ray.o.y, new_ray.o.z,
		// 	new_ray.d.x, new_ray.d.y, new_ray.d.z,
		// 	new_ray.depth
		// );
		if (container_is_intersect(&scene->obj_container, &new_ray, &new_isect))
		{
			hemi = trace(scene, &new_ray, &new_isect);
			vec_add_mut(&aggregate_color, &hemi);
		}
	}
	vec_color_clamp_mut(&aggregate_color);
	return (aggregate_color);
}

void	render_image(const t_scene *scene, SDL_Surface *surf)
{
	t_intersection	isect;
	t_ray			ray;
	t_point2		pixel;

	pixel = (t_point2){0, 0};
	while (pixel.y < surf->h)
	{
		pixel.x = 0;
		while (pixel.x < surf->w)
		{
			t_vec	aggregate = vec_make0();
			for (size_t i = 0; i < 8; i++)
			{
				isect.t = INFINITY;
				camera_cast_ray(&scene->camera, &pixel, &ray);
				if (container_is_intersect(&scene->obj_container, &ray, &isect))
				{
					t_vec idk = trace(scene, &ray, &isect);
					vec_add_mut(&aggregate, &idk);
				}
			}
			vec_mult_mut_scalar(&aggregate, 1.0 / 8.0);
			vec_color_clamp_mut(&aggregate);
			// isect.t = INFINITY;
			// camera_cast_ray(&scene->camera, &pixel, &ray);
			// if (container_is_intersect(&scene->obj_container, &ray, &isect))
			// 	ui_put_pixel(surf,
			// 		(size_t)pixel.x,
			// 			(size_t)pixel.y, vec_to_ints(trace(scene, &ray, &isect)));
			// else
			ui_put_pixel(surf, (size_t)pixel.x, (size_t)pixel.y, vec_to_int(&aggregate));
			pixel.x++;
		}
		pixel.y++;
	}
}
