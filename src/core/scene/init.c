/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/07 16:50:22 by nmartins       #+#    #+#                */
/*   Updated: 2019/11/07 19:46:17 by nmartins      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"

void		set_sphere(t_sphere *sphere)
{
	sphere->origin = (t_vec){0, 0, 5};
	sphere->radius = 1.0;
}

void		set_plane(t_plane *plane)
{
	plane->origin = (t_vec){0, -1, 0};
	plane->normal = (t_vec){0, 1, 0};
}

t_object	*make_object(void)
{
	t_object		*obj;

	obj = malloc(sizeof(t_object));
	if (!obj)
		return (NULL);
	return (obj);
}

void	scene_init(t_scene *scene)
{
	scene->obj_container.root = NULL;
	scene->camera = (t_camera){
		.origin = (t_vec){-1, 0, -2},
		.rotation = (t_vec){0, 0, 1},
		.fov = 45,
	};
	t_object	*obj;
	obj = make_object();
	obj->shape.type = SHAPE_SPHERE;
	obj->material.color = vec_mk(0,0,0);
	obj->material.emission = vec_mk(0,0,0);
	set_sphere(&obj->shape.val.as_sphere);
	container_push_object(&scene->obj_container, obj);
	obj = make_object();
	obj->shape.type = SHAPE_SPHERE;
	obj->material.color = vec_mk(0,0,0);
	obj->material.emission = vec_mk(555,200,200);
	set_sphere(&obj->shape.val.as_sphere);
	obj->shape.val.as_sphere.origin.x -= 2;
	container_push_object(&scene->obj_container, obj);
	obj = make_object();
	obj->shape.type = SHAPE_SPHERE;
	obj->material.color = vec_mk(0,0,0);
	obj->material.emission = vec_mk(200,200,555);
	set_sphere(&obj->shape.val.as_sphere);
	obj->shape.val.as_sphere.origin.x += 2;
	container_push_object(&scene->obj_container, obj);
	obj = make_object();
	obj->shape.type = SHAPE_PLANE;
	obj->material.color = vec_mk(0,0,0);
	obj->material.emission = vec_mk(0,0,0);
	set_plane(&obj->shape.val.as_plane);
	container_push_object(&scene->obj_container, obj);
}
