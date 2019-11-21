/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   renderer.h                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/07 16:32:18 by nmartins       #+#    #+#                */
/*   Updated: 2019/11/20 19:56:20 by nmartins      ########   odam.nl         */
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
	struct s_app	*app;

	volatile bool	done;

	t_point2		start_position;
	t_point2		end_position;
}				t_render_segm;

struct s_app;
struct s_textures;

REAL			ui_get_fps(int do_tick);
void			render_image(struct s_app *scene, t_realbuffer *buf);
void			render_segm(void *data);
t_vec			trace(const t_scene *scene, const t_ray *ray,
	t_intersection *isect, struct s_textures *tex);

#endif
