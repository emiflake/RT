/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init_obj.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/20 17:25:04 by nmartins       #+#    #+#                */
/*   Updated: 2019/11/20 18:01:42 by nmartins      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

#include "scene.h"

static t_object	*make_object(void)
{
	t_object		*obj;

	obj = malloc(sizeof(t_object));
	if (!obj)
		return (NULL);
	return (obj);
}

static void		init_material(t_material *mat, const t_json_value *val)
{
	dict_def_vec(val, "emission", (t_vec){0, 0, 0}, &mat->emission);
	dict_def_vec(val, "color", (t_vec){0, 0, 0}, &mat->color);
	mat->is_parallel = (bool)dict_def_double(val, "parallel_light", false);
	mat->blurriness = dict_def_double(val, "blurry", 0.999);
	mat->blurriness *= mat->blurriness;
	mat->reflective = dict_def_double(val, "reflective", 0);
	mat->refraction = dict_def_double(val, "refraction", 1.001);
	mat->transparent = dict_def_double(val, "transparent", 0);
	mat->texture = dict_def_string(val, "texture", NULL);
}

t_object		*object_init(const t_json_value *dict)
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
			return (NULL);
		init_material(&obj->material, dict);
		return (obj);
	}
}
