/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   app_init.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/04 16:45:32 by nmartins       #+#    #+#                */
/*   Updated: 2019/11/19 23:11:00 by nmartins      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

#include "ui.h"
#include "core/scene/scene.h"

int			usage(int argc, char **argv)
{
	(void)argc;
	ft_printf(
		"Usage: %s <scene>\n" \
		"",\
		argv[0]);
	return (FAILURE);
}

int			app_init(t_app *app, int argc, char **argv)
{
	if (argc < 2)
		return (usage(argc, argv));
	ft_printf("- Welcome to RT! -\n");
	app->running = true;
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
	if (window_init(&app->window, &app->settings) != SUCCESS)
	{
		scene_free(&app->scene);
		rb_free(app->realbuf);
		return (FAILURE);
	}
	app->camera_selected = true;
	app->selected_object = NULL;
	gfx_init(&app->gfx_ctx);
	srand(time(NULL));
	return (SUCCESS);
}
