/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   app_init.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/04 16:45:32 by nmartins       #+#    #+#                */
/*   Updated: 2019/11/21 16:59:20 by nmartins      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

#include "ui.h"
#include "core/scene/scene.h"

int				usage(int argc, char **argv)
{
	(void)argc;
	ft_printf(
		"Usage: %s <scene>\n" \
		"",\
		argv[0]);
	return (FAILURE);
}

static void		app_defaults(t_app *app)
{
	app->running = true;
	app->camera_selected = true;
	app->selected_object = NULL;
}

static bool		window_setup(t_app *app)
{
	if (window_init(&app->window, &app->settings) != SUCCESS)
	{
		scene_free(&app->scene);
		rb_free(app->realbuf);
		return (FAILURE);
	}
	return (SUCCESS);
}

static bool		textures_setup(t_app *app)
{
	app->textures = texture_init();
	if (!app->textures)
	{
		SDL_DestroyWindow(app->window.win_ptr);
		scene_free(&app->scene);
		rb_free(app->realbuf);
		return (FAILURE);
	}
	return (SUCCESS);
}

int				app_init(t_app *app, int argc, char **argv)
{
	if (argc < 2)
		return (usage(argc, argv));
	app_defaults(app);
	keystate_init(&app->keys);
	if (settings_init(&app->settings) == FAILURE ||
		scene_init(&app->scene, argv[1]) == FAILURE)
		return (FAILURE);
	app->realbuf = rb_create(app->settings.width, app->settings.height);
	if (!app->realbuf)
	{
		scene_free(&app->scene);
		return (FAILURE);
	}
	if (window_setup(app) != SUCCESS)
		return (FAILURE);
	if (textures_setup(app) != SUCCESS)
		return (FAILURE);
	gfx_init(&app->gfx_ctx);
	srand(time(NULL));
	ft_printf("- Welcome to RT! -\n");
	return (SUCCESS);
}
