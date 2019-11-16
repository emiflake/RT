/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   renderer.h                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/07 16:32:18 by nmartins       #+#    #+#                */
/*   Updated: 2019/11/15 14:30:41 by nmartins      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDERER_H
# define RENDERER_H

# include <SDL2/SDL.h>

# include "core/scene/scene.h"

typedef struct	s_render_segm
{
	SDL_Surface		*surface;
	const t_scene	*scene;

	volatile bool	done;

	t_point2		start_position;
	t_point2		end_position;
}				t_render_segm;

REAL			ui_get_fps(int do_tick);
void			render_image(const t_scene *scene, SDL_Surface *surf);

#endif
