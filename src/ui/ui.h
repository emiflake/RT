/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ui.h                                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/28 14:50:54 by nmartins       #+#    #+#                */
/*   Updated: 2019/11/12 20:33:57 by nmartins      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef UI_H
# define UI_H

/*
** We will use SDL2 for handling all UI.
*/

# include <SDL2/SDL.h>

/*
** UI is responsible for handling window management.
** Actual rendering is done elsewhere (probably in `core`)
*/

# include "core/scene/scene.h"
# include "keystate.h"
# include "text.h"

typedef struct	s_gfx_context
{
	t_font		font;
}				t_gfx_context;

typedef struct	s_window
{
	SDL_Window	*win_ptr;
	SDL_Surface	*win_srf;
}				t_window;

typedef struct	s_app
{
	t_window		window;
	t_keystate		keys;

	t_gfx_context	gfx_ctx;

	t_scene			scene;

	bool			running;
}				t_app;

int				window_init(t_window *win);

int				app_init(t_app *app, int argc, char **argv);

int				app_free(t_app *app);

void			app_run(t_app *app);

int				gfx_init(t_gfx_context *app);

long			get_current_epoch(void);

void			prim_clear(SDL_Surface *surface, uint32_t color);

void			ui_put_pixel(
	SDL_Surface *surface, size_t x, size_t y, uint32_t color);
#endif
