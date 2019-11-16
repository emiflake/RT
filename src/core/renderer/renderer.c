/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   renderer.c                                         :+:    :+:            */
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

void	render_segm(void *data)
{
	t_render_segm	*segm;
	t_intersection	isect;
	t_ray			ray;
	t_point2		pixel;

	segm = data;
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
				if (bvh_is_intersect(segm->scene->bvh, &ray, &isect))
				{
					// aggregate = vec_adds(aggregate, (t_vec){255.0,255.0,255.0});
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
	bool			should_die;

	pool = threadpool_init(4);
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
	should_die = false;
	while (!should_die)
	{
		should_die = true;
		for (size_t i = 0; i < SEGMENT_COUNT; i++)
		{
			if (!segments[i].done)
				should_die = false;
		}
		usleep(10);
	}
	threadpool_free(pool);
	ui_get_fps(1);
}
