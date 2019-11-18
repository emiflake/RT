/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/26 16:32:43 by nmartins       #+#    #+#                */
/*   Updated: 2019/11/18 14:44:59 by jandre-d      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>
#include <assert.h>
#include <unistd.h>

#include "./algebra/shapes/shape.h"
#include "./common/common.h"
#include "./algebra/vector/vector.h"
#include "./json/json.h"

#include "./ui/ui.h"
#include "core/camera/camera.h"
#include "core/object/object.h"
#include "threadpool/threadpool.h"
#include "algebra/mmath/mmath.h"



#include <unistd.h>
#include <SDL2/SDL.h>
#include <ft_printf.h>
#include "renderer/renderer.h"
#include "../algebra/mmath/mmath.h"
#include "../ui/ui.h"
void			runnn(t_app *app)
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
		
		int x = 0;
		int y = 0;
		while (x < app->window.win_srf->w)
		{
			y = 0;
			while (y < app->window.win_srf->h)
			{
				int r = 255;
				int g = 0;
				int b = 255;


				((uint32_t*)app->window.win_srf->pixels)[y * app->window.win_srf->w + x] =  (uint32_t)r << 16 | (uint32_t)g << 8 | (uint32_t)b;
				y++;
			}
			x++;
		}
		

		SDL_UpdateWindowSurface(app->window.win_ptr);
	}
}

int			main(int argc, char **argv)
{
	t_app app;

	if (app_init(&app, argc, argv) == SUCCESS)
	{
		//app_run(&app);
		runnn(&app);
		//app_free(&app);
	}
	else
	{
		ft_printf("Oh no, something went wrong, shutting down...\n");
	}
	return (0);
}
