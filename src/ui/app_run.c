/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   app_run.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/04 16:53:03 by nmartins       #+#    #+#                */
/*   Updated: 2019/11/20 22:19:32 by nmartins      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <SDL2/SDL.h>
#include <ft_printf.h>

#include "core/renderer/renderer.h"
#include "algebra/mmath/mmath.h"
#include "ui.h"


static void		app_run_split(t_app *app)
{
	camera_recompute(&app->scene.camera,
		app->realbuf->width, app->realbuf->height);
	handle_mouse(app);
	update(app);
	if (app->scene.bvh)
		bvh_free(app->scene.bvh);
	app->scene.bvh = NULL;
	app->scene.bvh = bvh_construct(app->scene.obj_container.root);
	srand(time(NULL));
	render_image(app, app->realbuf);
	rb_compress(app->realbuf, app->window.win_srf);
	rb_inc_sample(app->realbuf);
	show_selected_object(app);
	dbg_text(app);
	SDL_UpdateWindowSurface(app->window.win_ptr);
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
				if (evt.key.keysym.scancode == SDL_SCANCODE_SPACE)
				{
					app->scene.camera.color_filter =
						fmod(app->scene.camera.color_filter + 1.0, 3.0);
					rb_clear(app->realbuf);
				}
				keystate_set_down(&app->keys, evt.key.keysym.scancode);
			}
			if (evt.type == SDL_KEYUP)
				keystate_set_up(&app->keys, evt.key.keysym.scancode);
		}
		app_run_split(app);
	}
}
