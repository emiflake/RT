/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   app_run.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/04 16:53:03 by nmartins       #+#    #+#                */
/*   Updated: 2019/11/17 14:23:10 by nmartins      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <SDL2/SDL.h>
#include <ft_printf.h>

#include "core/renderer/renderer.h"
#include "ui.h"

static void		camera_move(t_camera *camera, const t_vec *delta)
{
	camera->origin.x +=
		cos(camera->rotation.y) * delta->x - sin(camera->rotation.y) * delta->z;
	camera->origin.y += delta->y;
	camera->origin.z -=
		-cos(camera->rotation.y)
		* delta->z - sin(camera->rotation.y) * delta->x;
}

static void		update(t_app *a)
{
	const REAL	s = keystate_is_down(&a->keys, SDL_SCANCODE_LSHIFT) ? 2.0 : 0.5;
	t_vec		delta;
	t_camera	*cam;

	cam = &a->scene.camera;
	delta = (t_vec){0.0, 0.0, 0.0};
	delta.x += keystate_is_down(&a->keys, SDL_SCANCODE_D) * s;
	delta.x -= keystate_is_down(&a->keys, SDL_SCANCODE_A) * s;
	delta.y += keystate_is_down(&a->keys, SDL_SCANCODE_E) * s;
	delta.y -= keystate_is_down(&a->keys, SDL_SCANCODE_Q) * s;
	delta.z += keystate_is_down(&a->keys, SDL_SCANCODE_W) * s;
	delta.z -= keystate_is_down(&a->keys, SDL_SCANCODE_S) * s;
	camera_move(cam, &delta);
	cam->rotation.y += keystate_is_down(&a->keys, SDL_SCANCODE_LEFT) * s * 0.1;
	cam->rotation.y -= keystate_is_down(&a->keys, SDL_SCANCODE_RIGHT) * s * 0.1;
	cam->rotation.x += keystate_is_down(&a->keys, SDL_SCANCODE_DOWN) * s * 0.1;
	cam->rotation.x -= keystate_is_down(&a->keys, SDL_SCANCODE_UP) * s * 0.1;
}

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
}

void			app_run(t_app *app)
{
	SDL_Event	evt;

	while (app->running)
	{
		while (SDL_PollEvent(&evt))
		{
			if (evt.type == SDL_QUIT)
				app->running = false;
			if (evt.type == SDL_KEYDOWN)
			{
				if (evt.key.keysym.sym == SDLK_ESCAPE)
					app->running = false;
				keystate_set_down(&app->keys, evt.key.keysym.scancode);
			}
			if (evt.type == SDL_KEYUP)
				keystate_set_up(&app->keys, evt.key.keysym.scancode);
		}
		update(app);
		camera_recompute(&app->scene.camera,
			app->window.win_srf->w, app->window.win_srf->h);
		render_image(&app->scene, app->window.win_srf);
		dbg_text(app);
		SDL_UpdateWindowSurface(app->window.win_ptr);
	}
}
