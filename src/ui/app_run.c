/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   app_run.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/04 16:53:03 by nmartins       #+#    #+#                */
/*   Updated: 2019/11/07 19:19:52 by nmartins      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <SDL2/SDL.h>
#include <ft_printf.h>

#include "core/renderer/renderer.h"
#include "ui.h"

void	app_run(t_app *app)
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
