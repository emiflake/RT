/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   renderer.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/07 16:35:34 by nmartins       #+#    #+#                */
/*   Updated: 2019/11/14 19:05:29 by nmartins      ########   odam.nl         */
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
		new_ray.depth = ray->depth - 1;
		new_isect.t = INFINITY;
		if (container_is_intersect(&scene->obj_container, &new_ray, &new_isect))
		{
			hemi = trace(scene, &new_ray, &new_isect);
			t_vec temp = vec_mults_scalar(isect->obj_ptr->material.color, 1.0 / 255.0);
			vec_mult_mut(&hemi, &temp);
			vec_add_mut(&aggregate_color, &hemi);
		}
	}
	return (aggregate_color);
}


void	render_segm(void *data)
{
	t_render_segm	*segm = data;

	t_intersection	isect;
	t_ray			ray;
	t_point2		pixel;

	pixel = (t_point2){segm->start_position.x, segm->start_position.y};
	while (pixel.y < segm->end_position.y)
	{
		pixel.x = segm->start_position.x;
		while (pixel.x < segm->end_position.x)
		{
			t_vec	aggregate = vec_make0();
			for (size_t i = 0; i < SUPERSAMPLE; i++)
			{
				isect.t = INFINITY;
				camera_cast_ray(&segm->scene->camera, &pixel, &ray, i);
				if (container_is_intersect(&segm->scene->obj_container, &ray, &isect))
				{
					t_vec idk = trace(segm->scene, &ray, &isect);
					vec_add_mut(&aggregate, &idk);
				}
			}
			vec_mult_mut_scalar(&aggregate, 1.0 / SUPERSAMPLE);
			vec_color_clamp_mut(&aggregate);
			ui_put_pixel(segm->surface, (size_t)pixel.x, (size_t)pixel.y, vec_to_int(&aggregate));
			pixel.x++;
		}
		pixel.y++;
	}
	segm->done = true;
}

#define SEGMENT_COUNT 100

#define MULTITHREAD

void	render_image(const t_scene *scene, SDL_Surface *surf)
{
	t_render_segm	segments[SEGMENT_COUNT];
	t_work			work[SEGMENT_COUNT];
	t_threadpool	*pool;
	size_t			i;

	pool = threadpool_init(50);
	if (!pool)
	{
		exit(FAILURE);
	}
	i = 0;
	while (i < SEGMENT_COUNT)
	{
		segments[i].surface = surf;
		segments[i].scene = scene;
		segments[i].done = false;
		segments[i].start_position = (t_point2){0, i * surf->h / SEGMENT_COUNT};
		segments[i].end_position = (t_point2){surf->w, (i + 1) * surf->h / SEGMENT_COUNT};
		work[i].argument = &segments[i];
		work[i].fn = render_segm;
		threadpool_push_work(pool, &work[i]);
		i++;
	}
	bool should_die = false;
	while (!should_die)
	{
		should_die = true;
		for (size_t i = 0; i < SEGMENT_COUNT; i++)
		{
			if (!segments[i].done)
				should_die = false;
		}
		usleep(1);
	}
	threadpool_free(pool);
	ui_get_fps(1);
}
