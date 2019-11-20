/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   free.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/16 21:30:31 by nmartins       #+#    #+#                */
/*   Updated: 2019/11/19 23:04:38 by nmartins      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"

void	scene_free(t_scene *scene)
{
	container_free(scene->obj_container.root);
	if (scene->bvh)
		bvh_free(scene->bvh);
}
