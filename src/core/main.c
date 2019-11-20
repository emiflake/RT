/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/26 16:32:43 by nmartins       #+#    #+#                */
/*   Updated: 2019/11/20 17:24:29 by jandre-d      ########   odam.nl         */
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
#include "../perlin_noise/perlin_noise.h"
#include "../texture/texture.h"

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

		// int x = 0;
		// int y = 0;
		// while (x < app->window.win_srf->w)
		// {
		// 	y = 0;
		// 	while (y < app->window.win_srf->h)
		// 	{
		// 		float value = perlin_noise(perl, x, y, .003);
		// 		//ft_printf("%f", value);
		// 		int r = 0;
		// 		int g = 0;
		// 		int b = 0;
		// 		// if (sin(M_PI * y / 20) > 0 && sin(M_PI * x / 20) > 0)
		// 		// {
		// 		// 	r = ((float)255 * value);
		// 		// }
		// 		// else
		// 		// {
		// 		// 	r = ((float)142 * value);
		// 		// 	g = ((float)200 * value);
		// 		// 	b = ((float)200 * value);
		// 		// }

		// 		float t = (1 + sin(M_PI * y / 14)) / 3;
		// 		r = 255 * t;
		// 		g = 255 * t;
		// 		b = 255 * t;

		// 		((uint32_t*)app->window.win_srf->pixels)[y * app->window.win_srf->w + x] =  (uint32_t)r << 16 | (uint32_t)g << 8 | (uint32_t)b;
		// 		y++;
		// 	}
		// 	x++;
		// }


		SDL_UpdateWindowSurface(app->window.win_ptr);
	}
}

int			main(int argc, char **argv)
{
	t_app app;

	if (app_init(&app, argc, argv) == SUCCESS)
	{
		t_textures *textures;
		t_texture *texture;

		textures = texture_init();
		if (textures == NULL)
		{
			ft_printf("ERRROR");
			return (0);
		}
		
		texture = get_texture(textures, "internal.noise");
		if (texture == NULL)
		{
			ft_printf("eERROR2232322452");
			return (0);
		}
		
		if (!img_to_ppm_file(texture->img, "xxxxxxxx.ppm"))
		{
			ft_printf("oooh no...");
		}


		//app_run(&app);
		//runnn(&app);
		//app_free(&app);

	}
	else
	{
		ft_printf("Oh no, something went wrong, shutting down...\n");
	}
	return (0);
}
