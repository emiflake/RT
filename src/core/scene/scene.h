/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   scene.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/07 16:36:19 by nmartins       #+#    #+#                */
/*   Updated: 2019/11/12 16:20:06 by nmartins      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCENE_H
# define SCENE_H

# include "core/container/container.h"
# include "core/camera/camera.h"

typedef struct	s_scene
{
	t_object_container	obj_container;
	t_camera			camera;
}				t_scene;

void			scene_init(t_scene	*scene, const char *scene_filename);

#endif
