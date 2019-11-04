/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   app_init.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/04 16:45:32 by nmartins       #+#    #+#                */
/*   Updated: 2019/11/04 17:20:44 by nmartins      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

#include "ui.h"

int				app_init(t_app *app)
{
	ft_printf("- Welcome to RT! -\n");
	if (window_init(&app->window) != SUCCESS)
		return (FAILURE);
	app->running = true;
	keystate_init(&app->keys);
	gfx_init(&app->gfx_ctx);
	return (SUCCESS);
}
