/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ui.c                                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/04 16:53:03 by nmartins       #+#    #+#                */
/*   Updated: 2019/11/19 23:28:32 by nmartins      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <SDL2/SDL.h>
#include <ft_printf.h>

#include "core/renderer/renderer.h"
#include "algebra/mmath/mmath.h"
#include "ui.h"

void			dbg_text(t_app *app)
{
	REAL	sec_per_frame;
	char	*txt;

	sec_per_frame = ui_get_fps(0);
	ft_asprintf(&txt,
			"FPS:%7.3f\t\tSPF:%7.3f\n", 1.0 / sec_per_frame, sec_per_frame);
	ui_put_text_free(&app->gfx_ctx.font, &app->window,
		(t_point2){10, 10}, txt);
	ft_asprintf(&txt, "Welcome to our amazing RT");
	ui_put_text_free(&app->gfx_ctx.font,
		&app->window, (t_point2){10, 40}, txt);
	ft_asprintf(&txt, "Camera Position: %.2lf %.2lf %.2lf\n",
		app->scene.camera.origin.x,
		app->scene.camera.origin.y,
		app->scene.camera.origin.z);
	ui_put_text_free(&app->gfx_ctx.font,
		&app->window, (t_point2){10, 70}, txt);
	ft_asprintf(&txt, "Camera rotation: %.2lf %.2lf %.2lf\n",
		app->scene.camera.rotation.x,
		app->scene.camera.rotation.y,
		app->scene.camera.rotation.z);
	ui_put_text_free(&app->gfx_ctx.font,
		&app->window, (t_point2){10, 100}, txt);
	ft_asprintf(&txt, "Samples: %llu\n",
		app->realbuf->samples);
	ui_put_text_free(&app->gfx_ctx.font,
		&app->window, (t_point2){10, 130}, txt);
}

static void		check_object(
				t_app *app, t_ray *ray, t_intersection *isect, t_point2 coords)
{
	uint32_t	color;
	int			address;

	address = (size_t)coords.x + (size_t)coords.y * app->window.win_srf->w;
	color = (size_t)coords.x % 2 == 0 ? 0xff0000 : 0x00ff00;
	if (bvh_is_intersect(app->scene.bvh, ray, isect) &&
		app->selected_object == isect->obj_ptr)
	{
		for (size_t i = 0; i < 3; i++)
			for (size_t j = 0; j < 3; j++)
				ui_put_pixel(app->window.win_srf, (int)coords.x + i,
							 (int)coords.y + j, color);
	}
}

static void		set_isect(
			t_point2 *coords, t_point2 *pix, t_intersection *isect, t_app *app)
{
	pix->x = ((double)coords->x) * app->realbuf->width /
		app->window.win_srf->w;
	pix->y = ((double)coords->y) * app->realbuf->height /
		app->window.win_srf->h;
	isect->t = INFINITY;
}

void			show_selected_object(t_app *app)
{
	t_point2		coords;
	t_ray			ray;
	t_point2		pix;
	t_intersection	isect;

	if (!app->selected_object)
		return ;
	coords.y = 0;
	while (coords.y < app->realbuf->height)
	{
		coords.x = 0;
		while (coords.x < app->realbuf->width)
		{
			if ((int)coords.x % 2 == 0 != (int)coords.y % 2 == 0)
			{
				set_isect(&coords, &pix, &isect, app);
				camera_cast_ray(&app->scene.camera, &pix, &ray);
				check_object(app, &ray, &isect, coords);
			}
			coords.x += 3;
		}
		coords.y += 3;
	}
}
