/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ui.h                                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/28 14:50:54 by nmartins       #+#    #+#                */
/*   Updated: 2019/11/17 16:24:03 by nmartins      ########   odam.nl         */
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
# include "core/settings/settings.h"
# include "keystate.h"
# include "text.h"
# include "core/renderer/realbuffer.h"

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

	t_settings		settings;

	t_realbuffer	*realbuf;

	bool			running;
}				t_app;

int				window_init(t_window *win);

int				app_init(t_app *app, int argc, char **argv);

void			app_free(t_app *app);

void			app_run(t_app *app);

int				gfx_init(t_gfx_context *app);
void			gfx_free(t_gfx_context *app);

long			get_current_epoch(void);

void			prim_clear(SDL_Surface *surface, uint32_t color);

void			ui_put_pixel(
	SDL_Surface *surface, size_t x, size_t y, uint32_t color);
#endif
