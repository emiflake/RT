/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   app_run.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/04 16:53:03 by nmartins       #+#    #+#                */
/*   Updated: 2019/11/15 19:11:31 by nmartins      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <SDL2/SDL.h>
#include <ft_printf.h>

#include "core/renderer/renderer.h"
#include "ui.h"

static void	camera_move(t_camera *camera, const t_vec *delta)
{
	camera->origin.x +=
		cos(camera->rotation.y) * delta->x - sin(camera->rotation.y) * delta->z;
	camera->origin.y += delta->y;
	camera->origin.z -=
		-cos(camera->rotation.y)
		* delta->z - sin(camera->rotation.y) * delta->x;
}

static void		update(t_app *app)
{
	const REAL 		speed = keystate_is_down(&app->keys, SDL_SCANCODE_LSHIFT) ? 2.0 : 0.5;
	t_vec			delta;

	delta = (t_vec){0.0, 0.0, 0.0};
	delta.x += keystate_is_down(&app->keys, SDL_SCANCODE_D) * speed;
	delta.x -= keystate_is_down(&app->keys, SDL_SCANCODE_A) * speed;
	delta.y += keystate_is_down(&app->keys, SDL_SCANCODE_E) * speed;
	delta.y -= keystate_is_down(&app->keys, SDL_SCANCODE_Q) * speed;
	delta.z += keystate_is_down(&app->keys, SDL_SCANCODE_W) * speed;
	delta.z -= keystate_is_down(&app->keys, SDL_SCANCODE_S) * speed;
	camera_move(&app->scene.camera, &delta);
	app->scene.camera.rotation.y += keystate_is_down(&app->keys, SDL_SCANCODE_LEFT) * speed * 0.1;
	app->scene.camera.rotation.y -= keystate_is_down(&app->keys, SDL_SCANCODE_RIGHT) * speed * 0.1;
	app->scene.camera.rotation.x += keystate_is_down(&app->keys, SDL_SCANCODE_DOWN) * speed * 0.1;
	app->scene.camera.rotation.x -= keystate_is_down(&app->keys, SDL_SCANCODE_UP) * speed * 0.1;
}

void			app_run(t_app *app)
{
	SDL_Event	evt;
	char		*fps_text;
	REAL		sec_per_frame;

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
		prim_clear(app->window.win_srf, 0x000000);
		camera_recompute(&app->scene.camera,
			app->window.win_srf->w, app->window.win_srf->h);
		sec_per_frame = ui_get_fps(0);
		render_image(&app->scene, app->window.win_srf);
		ft_asprintf(&fps_text,
				"FPS:%7.3f\t\tSPF:%7.3f\n", 1.0 / sec_per_frame, sec_per_frame);
		ui_put_text_free(&app->gfx_ctx.font, &app->window,
			(t_point2){10, 10}, fps_text);
		ft_asprintf(&fps_text, "Welcome to our amazing RT");
		ui_put_text_free(&app->gfx_ctx.font,
			&app->window, (t_point2){10, 40}, fps_text);
		SDL_UpdateWindowSurface(app->window.win_ptr);
	}
}
