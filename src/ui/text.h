/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   text.h                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/04 17:01:46 by nmartins       #+#    #+#                */
/*   Updated: 2019/11/04 17:57:13 by nmartins      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEXT_H
# define TEXT_H

# include <SDL2/SDL_ttf.h>

# include "../algebra/point2/point2.h"

struct s_window;

typedef struct	s_font
{
	TTF_Font	*font;
}				t_font;

t_font			font_load(const char *filename, size_t size);

void			ui_put_text(
	const t_font *font, struct s_window *win, t_point2 p, const char *text);
void			ui_put_text_free(
	const t_font *font, struct s_window *win, t_point2 p, char *text);

#endif
