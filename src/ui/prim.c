/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   prim.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/04 17:58:03 by nmartins       #+#    #+#                */
/*   Updated: 2019/11/04 17:58:10 by nmartins      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ui.h"

void		prim_clear(SDL_Surface *surface, uint32_t color)
{
	uint32_t	*pixels_arr;
	size_t		index;

	pixels_arr = (uint32_t*)surface->pixels;
	index = 0;
	while (index < (size_t)(surface->w * surface->h))
	{
		pixels_arr[index] = color;
		index++;
	}
}
