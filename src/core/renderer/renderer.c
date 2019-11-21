/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   renderer.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/07 16:35:34 by nmartins       #+#    #+#                */
/*   Updated: 2019/11/21 18:27:38 by nmartins      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <ft_printf.h>
#include <pthread.h>
#include <unistd.h>

#include "threadpool/threadpool.h"
#include "algebra/mmath/mmath.h"
#include "algebra/intersection/intersection.h"
#include "renderer.h"
#include "ui/ui.h"

static void		add_filtered(
	t_vec *aggregate, t_render_segm *s, t_point2 p)
{
	int		filter;
	REAL	sat;

	filter = s->scene->camera.color_filter;
	if (filter >= 1 && filter <= 2)
	{
		sat = (aggregate->x + aggregate->y + aggregate->z) * DELTAVAL;
		sat = (sat < DELTAVAL) ? DELTAVAL : sat;
		*aggregate = (filter == 1) ? SEPIA_VAL : WB_VAL;
		vec_mult_mut_scalar(aggregate, sat);
	}
	rb_add_sample(s->buf, p.x, p.y, aggregate);
}

void			render_segm(void *data)
{
	t_render_segm	*s;
	t_intersection	isect;
	t_ray			ray;
	t_point2		pixel;
	t_vec			aggregate;

	s = (t_render_segm*)data;
	pixel = (t_point2){s->start_position.x, s->start_position.y};
	while (pixel.y < s->end_position.y)
	{
		pixel.x = s->start_position.x;
		while (pixel.x < s->end_position.x)
		{
			isect.t = INFINITY;
			camera_cast_ray(&s->scene->camera, &pixel, &ray);
			if (bvh_is_intersect(s->scene->bvh, &ray, &isect))
			{
				aggregate = trace(s->scene, &ray, &isect, s->app->textures);
				add_filtered(&aggregate, s, pixel);
			}
			pixel.x++;
		}
		pixel.y++;
	}
	s->done = true;
}

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
