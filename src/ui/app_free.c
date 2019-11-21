/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   app_free.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/16 21:25:51 by nmartins       #+#    #+#                */
/*   Updated: 2019/11/21 17:30:16 by nmartins      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include "texture/texture.h"
#include "ui.h"

void	app_free(t_app *app)
{
	gfx_free(&app->gfx_ctx);
	SDL_DestroyWindow(app->window.win_ptr);
	scene_free(&app->scene);
	rb_free(app->realbuf);
	textures_free(app->textures);
}
