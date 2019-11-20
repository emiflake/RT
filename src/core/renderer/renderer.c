/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   renderer.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/07 16:35:34 by nmartins       #+#    #+#                */
/*   Updated: 2019/11/19 23:05:48 by nmartins      ########   odam.nl         */
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
			isect.t = INFINITY;
			camera_cast_ray(&segm->scene->camera, &pixel, &ray);
			if (bvh_is_intersect(segm->scene->bvh, &ray, &isect))
			{
				t_vec idk = trace(segm->scene, &ray, &isect);
				vec_add_mut(&aggregate, &idk);
			}
			rb_add_sample(segm->buf, (size_t)pixel.x, (size_t)pixel.y, &aggregate);
			pixel.x++;
		}
		pixel.y++;
	}
	segm->done = true;
}

#define SEGMENT_COUNT 100

void	render_image(const t_scene *scene, t_realbuffer *buf)
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
		segments[i].buf = buf;
		segments[i].scene = scene;
		segments[i].done = false;
		segments[i].start_position = (t_point2){0, i * buf->height / SEGMENT_COUNT};
		segments[i].end_position = (t_point2){buf->width, (i + 1) * buf->height / SEGMENT_COUNT};
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
