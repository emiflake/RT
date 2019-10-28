/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ui.h                                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/28 14:50:54 by nmartins       #+#    #+#                */
/*   Updated: 2019/10/28 14:53:54 by nmartins      ########   odam.nl         */
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

typedef struct	s_window
{
	SDL_Window	*win_ptr;
	SDL_Surface	*win_srf;
}				t_window;

#endif