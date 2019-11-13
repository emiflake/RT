/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   app_init.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/04 16:45:32 by nmartins       #+#    #+#                */
/*   Updated: 2019/11/12 16:39:32 by nmartins      ########   odam.nl         */
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

int				app_init(t_app *app, int argc, char **argv)
{
	if (window_init(&app->window) != SUCCESS)
		return (FAILURE);
	if (argc < 2)
		return (usage(argc, argv));
	ft_printf("- Welcome to RT! -\n");
	app->running = true;
	keystate_init(&app->keys);
	gfx_init(&app->gfx_ctx);
	scene_init(&app->scene, argv[1]);
	srand(time(NULL));
	return (SUCCESS);
}
