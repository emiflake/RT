/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   window_init.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/04 16:43:58 by nmartins       #+#    #+#                */
/*   Updated: 2019/11/16 01:04:50 by nmartins      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <SDL2/SDL.h>

#include "core/settings/settings.h"
#include "ui.h"

int				window_init(t_window *win, const t_settings *settings)
{
	if (SDL_Init(SDL_INIT_VIDEO) != 0)
		return (FAILURE);
	win->win_ptr = SDL_CreateWindow(
		"RT", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
		settings->width, settings->height, SDL_WINDOW_SHOWN);
	if (!win->win_ptr)
		return (FAILURE);
	win->win_srf = SDL_GetWindowSurface(win->win_ptr);
	if (!win->win_srf)
		return (FAILURE);
	return (SUCCESS);
}
