/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   app_update.c                                       :+:    :+:            */
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

static void		set_delta(t_app *a, t_vec *delta, const REAL s)
{
	*delta = (t_vec){0.0, 0.0, 0.0};
	delta->x += keystate_is_down(&a->keys, SDL_SCANCODE_D) * s;
	delta->x -= keystate_is_down(&a->keys, SDL_SCANCODE_A) * s;
	delta->y += keystate_is_down(&a->keys, SDL_SCANCODE_E) * s;
	delta->y -= keystate_is_down(&a->keys, SDL_SCANCODE_Q) * s;
	delta->z += keystate_is_down(&a->keys, SDL_SCANCODE_W) * s;
	delta->z -= keystate_is_down(&a->keys, SDL_SCANCODE_S) * s;
}

static void		set_rotation(t_app *a, t_vec *rotation, const REAL s)
{
	*rotation = (t_vec){0.0, 0.0, 0.0};
	rotation->y += keystate_is_down(&a->keys, SDL_SCANCODE_LEFT) * s / 5.0;
	rotation->y -= keystate_is_down(&a->keys, SDL_SCANCODE_RIGHT) * s / 5.0;
	rotation->x += keystate_is_down(&a->keys, SDL_SCANCODE_DOWN) * s / 5.0;
	rotation->x -= keystate_is_down(&a->keys, SDL_SCANCODE_UP) * s / 5.0;
	rotation->z -= keystate_is_down(&a->keys, SDL_SCANCODE_RCTRL) * s / 5.0;
	rotation->z += keystate_is_down(&a->keys, SDL_SCANCODE_KP_0) * s / 5.0;
}

void			update(t_app *a)
{
	const REAL	s = keystate_is_down(&a->keys, SDL_SCANCODE_LSHIFT) ? 2.0 : 0.5;
	t_vec		delta;
	t_vec		rotation;
	t_camera	*cam;

	a->camera_selected = keystate_is_down(&a->keys, SDL_SCANCODE_K) ?
		true : a->camera_selected;
	a->camera_selected = keystate_is_down(&a->keys, SDL_SCANCODE_O) ?
		false : a->camera_selected;
	cam = &a->scene.camera;
	set_delta(a, &delta, s);
	set_rotation(a, &rotation, s);
	if (a->camera_selected)
	{
		camera_move(cam, &delta);
		vec_add_mut(&cam->rotation, &rotation);
	}
	else if (a->selected_object != NULL)
	{
		move_shape(&a->selected_object->shape, &delta, s);
		rotate_shape(&a->selected_object->shape, &rotation);
	}
	if (keystate_any(&a->keys))
		rb_clear(a->realbuf);
}
