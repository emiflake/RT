/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   app_run.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/04 16:53:03 by nmartins       #+#    #+#                */
/*   Updated: 2019/11/18 10:03:47 by nmartins      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <SDL2/SDL.h>
#include <ft_printf.h>

#include "core/renderer/renderer.h"
#include "algebra/mmath/mmath.h"
#include "ui.h"

#define CAMERA 0
#define OBJECT 1

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
	static bool		selected = CAMERA;
	static t_object_container_node	*cur_object = NULL;
	t_vec		delta;
	t_vec		rotation;
	t_camera	*cam;

	if (!cur_object)
	cur_object = a->scene.obj_container.root;
	selected = keystate_is_down(&a->keys, SDL_SCANCODE_K) ? CAMERA : selected;
	selected = keystate_is_down(&a->keys, SDL_SCANCODE_O) ? OBJECT : selected;
	cam = &a->scene.camera;
	delta = (t_vec){0.0, 0.0, 0.0};
	delta.x += keystate_is_down(&a->keys, SDL_SCANCODE_D) * s;
	delta.x -= keystate_is_down(&a->keys, SDL_SCANCODE_A) * s;
	delta.y += keystate_is_down(&a->keys, SDL_SCANCODE_E) * s;
	delta.y -= keystate_is_down(&a->keys, SDL_SCANCODE_Q) * s;
	delta.z += keystate_is_down(&a->keys, SDL_SCANCODE_W) * s;
	delta.z -= keystate_is_down(&a->keys, SDL_SCANCODE_S) * s;
	rotation = (t_vec){0.0, 0.0, 0.0};
	rotation.y += keystate_is_down(&a->keys, SDL_SCANCODE_LEFT) * M_PI / 180;
	rotation.y -= keystate_is_down(&a->keys, SDL_SCANCODE_RIGHT) * M_PI / 180;
	rotation.x += keystate_is_down(&a->keys, SDL_SCANCODE_DOWN) * M_PI / 180;
	rotation.x -= keystate_is_down(&a->keys, SDL_SCANCODE_UP) * M_PI / 180;
	rotation.z -= keystate_is_down(&a->keys, SDL_SCANCODE_RCTRL) * M_PI / 180;
	rotation.z += keystate_is_down(&a->keys, SDL_SCANCODE_KP_0) * M_PI / 180;
	if (selected == CAMERA)
	{
		camera_move(cam, &delta);
		vec_add_mut(&cam->rotation, &rotation);
	}
	if (selected == OBJECT)
	{
		if (keystate_is_down(&a->keys, SDL_SCANCODE_TAB))
		{
			if (cur_object->next)
				cur_object = cur_object->next;
			else
				cur_object = a->scene.obj_container.root;
		}
		move_shape(&cur_object->val->shape, &delta, 1);
		rotate_shape(&cur_object->val->shape, &rotation);
	}

	if (keystate_any(&a->keys))
		rb_clear(a->realbuf);
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
	ft_asprintf(&txt, "Samples: %llu\n",
		app->realbuf->samples);
	ui_put_text_free(&app->gfx_ctx.font,
		&app->window, (t_point2){10, 130}, txt);
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
			app->realbuf->width, app->realbuf->height);
		srand(time(NULL));
		render_image(&app->scene, app->realbuf);
		rb_compress(app->realbuf, app->window.win_srf);
		rb_inc_sample(app->realbuf);
		dbg_text(app);
		SDL_UpdateWindowSurface(app->window.win_ptr);
	}
}
