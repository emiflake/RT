/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/07 16:50:22 by nmartins       #+#    #+#                */
/*   Updated: 2019/11/15 23:55:01 by nmartins      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"
#include "json/json.h"
#include <ft_printf.h>
#include <math.h>
#include <unistd.h>

t_object	*make_object(void)
{
	t_object		*obj;

	obj = malloc(sizeof(t_object));
	if (!obj)
		return (NULL);
	return (obj);
}

void		camera_init(t_camera *cam, const t_json_value *camera_dict)
{
	if (!camera_dict)
	{
		ft_printf("[WARN] Could not find camera in scene, using default\n");
		*cam = (t_camera){
			.origin = (t_vec){0, 1, -5.9},
			.rotation = (t_vec){0, 0, 0},
			.fov = 45,
		};
	}
	else
	{
		cam->fov = dict_def_double(camera_dict, "fov", 90);
		dict_def_vec(camera_dict, "origin", (t_vec){0, 0, 0}, &cam->origin);
		dict_def_vec(camera_dict, "rotation", (t_vec){0, 0, 0}, &cam->rotation);
		ft_printf("[INFO] Camera all ready to go!\n");
	}
}

void		init_material(t_material *mat, const t_json_value *val)
{
	dict_def_vec(val, "emission", (t_vec){0, 0, 0}, &mat->emission);
	dict_def_vec(val, "color", (t_vec){0, 0, 0}, &mat->color);
}

t_object	*object_init(const t_json_value *dict)
{
	t_json_value	*type_val;
	t_object		*obj;

	if (!dict)
		return (NULL);
	type_val = dict_get(dict, "type");
	if (!type_val || type_val->type != JSON_STRING)
	{
		ft_printf("[WARN] Found weird type value not JSONString, namely:\n");
		json_debug(type_val);
		return (NULL);
	}
	else
	{
		ft_printf("[INFO] Loading object of type `%s`\n",
			type_val->value.as_string);
		obj = make_object();
		if (!init_shape(&obj->shape, dict))
		{
			ft_printf("[ERR] Could not initialize shape\
			near the following object:\n");
			json_debug(dict);
			return (NULL);
		}
		init_material(&obj->material, dict);
		return (obj);
	}
}

void		objects_init(t_object_container *cont, const t_json_value *val)
{
	t_object			*obj;
	t_json_list_node	*node;
	size_t				i;

	if (!val || val->type != JSON_LIST)
	{
		ft_printf("[ERR]  `objects` isn't a list\n");
		return ;
	}
	i = 0;
	node = val->value.as_list.root;
	while (node)
	{
		obj = object_init(node->value);
		if (obj)
			container_push_object(cont, obj);
		else
			ft_printf("[ERR]  Could not create object\n");
		node = node->next;
		i++;
	}
	ft_printf("[INFO] Allocated %llu objects\n", i);
}

void		scene_init(t_scene *scene, const char *scene_filename)
{
	t_json_value	*json_root;

	json_root = read_json(scene_filename);
	if (!json_root)
	{
		ft_printf("Scene file could not be loaded.\n");
		exit(FAILURE); // TODO: fix leaks caused by early exit
	}
	camera_init(&scene->camera, dict_get(json_root, "camera"));
	scene->obj_container.root = NULL;
	objects_init(&scene->obj_container, dict_get(json_root, "objects"));
	scene->bvh = bvh_construct(scene->obj_container.root);
}
