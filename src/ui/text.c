/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   text.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/04 17:13:07 by nmartins       #+#    #+#                */
/*   Updated: 2019/11/12 18:40:14 by nmartins      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

#include <stdlib.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

#include "text.h"
#include "ui.h"

void			ui_put_text_free(
	const t_font *font, struct s_window *win, t_point2 p, char *text)
{
	ui_put_text(font, win, p, text);
	free(text);
}

void			ui_put_text(
	const t_font *font, t_window *win, t_point2 pos, const char *text)
{
	SDL_Surface	*surf;
	SDL_Rect	render_quad;
	t_point2	dimensions;

	surf = TTF_RenderText_Blended(font->font, text,
		(SDL_Color){255, 255, 255, 255});
	if (!surf)
	{
		ft_printf("%s\n", SDL_GetError());
		ft_printf("Failed to render text!\n");
		exit(0);
	}
	dimensions.x = surf->w;
	dimensions.y = surf->h;
	render_quad = (SDL_Rect){pos.x, pos.y, dimensions.x, dimensions.y};
	SDL_BlitSurface(surf,
		NULL,
		win->win_srf,
		&render_quad);
	SDL_FreeSurface(surf);
}

t_font			font_load(const char *filename, size_t size)
{
	return ((t_font){TTF_OpenFont(filename, size)});
}
