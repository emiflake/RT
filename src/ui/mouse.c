/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   mouse.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/04 16:53:03 by nmartins       #+#    #+#                */
/*   Updated: 2019/11/21 16:53:21 by nmartins      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <SDL2/SDL.h>
#include <ft_printf.h>

#include "core/renderer/renderer.h"
#include "algebra/mmath/mmath.h"
#include "ui.h"

void			handle_mouse(t_app *app)
{
	uint32_t		mstate;
	int				mpos[2];
	t_ray			ray;
	t_point2		pix;
	t_intersection	isect;

	mstate = SDL_GetMouseState(&mpos[0], &mpos[1]);
	if (mstate & SDL_BUTTON(SDL_BUTTON_LEFT))
	{
		app->camera_selected = false;
		pix.x = ((double)mpos[0])
			* app->realbuf->width / app->window.win_srf->w;
		pix.y = ((double)mpos[1])
			* app->realbuf->height / app->window.win_srf->h;
		isect.t = INFINITY;
		camera_cast_ray(&app->scene.camera, &pix, &ray);
		if (bvh_is_intersect(app->scene.bvh, &ray, &isect))
			app->selected_object = isect.obj_ptr;
	}
	if (mstate & SDL_BUTTON(SDL_BUTTON_RIGHT))
	{
		app->camera_selected = true;
		app->selected_object = NULL;
	}
}
