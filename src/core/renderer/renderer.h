/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   renderer.h                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/07 16:32:18 by nmartins       #+#    #+#                */
/*   Updated: 2019/11/17 18:23:38 by nmartins      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDERER_H
# define RENDERER_H

# include <SDL2/SDL.h>

# include "realbuffer.h"
# include "core/scene/scene.h"

typedef struct	s_render_segm
{
	t_realbuffer	*buf;
	const t_scene	*scene;

	volatile bool	done;

	t_point2		start_position;
	t_point2		end_position;
}				t_render_segm;

REAL			ui_get_fps(int do_tick);
void			render_image(const t_scene *scene, t_realbuffer *surf);
void			render_segm(void *data);
void			render_image(const t_scene *scene, t_realbuffer *surf);
t_vec			trace(
				const t_scene *scene, const t_ray *ray, t_intersection *isect);

#endif
