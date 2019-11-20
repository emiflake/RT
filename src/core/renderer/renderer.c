/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   renderer.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/07 16:35:34 by nmartins       #+#    #+#                */
/*   Updated: 2019/11/20 20:15:34 by nmartins      ########   odam.nl         */
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

void			render_segm(void *data)
{
	t_render_segm	*segm;
	t_intersection	isect;
	t_ray			ray;
	t_point2		pixel;
	t_vec			aggregate;

	segm = data;
	pixel = (t_point2){segm->start_position.x, segm->start_position.y};
	while (pixel.y < segm->end_position.y)
	{
		pixel.x = segm->start_position.x;
		while (pixel.x < segm->end_position.x)
		{
			isect.t = INFINITY;
			camera_cast_ray(&segm->scene->camera, &pixel, &ray);
			if (bvh_is_intersect(segm->scene->bvh, &ray, &isect))
			{
				aggregate = trace(segm->scene, &ray, &isect, segm->app->textures);
				rb_add_sample(segm->buf, pixel.x, pixel.y, &aggregate);
			}
			pixel.x++;
		}
		pixel.y++;
	}
	segm->done = true;
}

#define SEGMENT_COUNT 100

static void		prepare_segment(
	t_render_segm *s, size_t i, t_app *app, t_realbuffer *buf)
{
	s->buf = buf;
	s->scene = &app->scene;
	s->app = app;
	s->done = false;
	s->start_position = (t_point2){0, i * buf->height / SEGMENT_COUNT};
	s->end_position =
		(t_point2){buf->width, (i + 1) * buf->height / SEGMENT_COUNT};
}

static void		wait_for_all(t_render_segm *segments)
{
	bool			should_die;
	size_t			i;

	should_die = false;
	while (!should_die)
	{
		should_die = true;
		i = 0;
		while (i < SEGMENT_COUNT)
		{
			if (!segments[i].done)
				should_die = false;
			i++;
		}
		usleep(10);
	}
}

void			render_image(t_app *scene, t_realbuffer *buf)
{
	t_render_segm	segments[SEGMENT_COUNT];
	t_work			work[SEGMENT_COUNT];
	t_threadpool	*pool;
	size_t			i;

	pool = threadpool_init(4);
	if (!pool)
		exit(FAILURE);
	i = 0;
	while (i < SEGMENT_COUNT)
	{
		prepare_segment(&segments[i], i, scene, buf);
		work[i].argument = &segments[i];
		work[i].fn = render_segm;
		threadpool_push_work(pool, &work[i]);
		i++;
	}
	wait_for_all(segments);
	threadpool_free(pool);
	ui_get_fps(1);
}
