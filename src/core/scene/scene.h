/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   scene.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/07 16:36:19 by nmartins       #+#    #+#                */
/*   Updated: 2019/11/20 17:26:42 by nmartins      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCENE_H
# define SCENE_H

# include "core/container/container.h"
# include "core/camera/camera.h"

typedef struct	s_scene
{
	t_object_container	obj_container;
	t_bvh_node			*bvh;
	t_camera			camera;
}				t_scene;

int				scene_init(t_scene *scene, const char *scene_filename);
void			scene_free(t_scene *scene);
t_object		*object_init(const t_json_value *dict);

#endif
