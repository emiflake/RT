/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   putpixel.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/07 16:45:19 by nmartins       #+#    #+#                */
/*   Updated: 2019/11/07 16:45:30 by nmartins      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ui.h"

void		ui_put_pixel(
	SDL_Surface *surface, size_t x, size_t y, uint32_t color)
{
	uint32_t *pixels_arr;
	uint32_t *loc;

	pixels_arr = (uint32_t*)surface->pixels;
	if (x >= (size_t)surface->w && y >= (size_t)surface->h)
		return ;
	loc = &pixels_arr[x + y * surface->w];
	*loc = color;
}
