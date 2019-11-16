/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/12 18:03:38 by nmartins       #+#    #+#                */
/*   Updated: 2019/11/13 01:02:45 by nmartins      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>
#include <assert.h>

#include "common/common.h"
#include "shape.h"
#include "json/json.h"

const static t_shape_init_kvp	g_shape_init_map[] = {
	{ "sphere", sphere_init },
	{ "plane", plane_init },
	{ "disk", disk_init },
	{ "square", square_init },
	{ "triangle", triangle_init },
	{ "cylinder", cylinder_init },
	{ "cone", cone_init },
	{ "cube", cube_init },
	{ "pyramid", pyramid_init },
	{ "tetrahedron", tetrahedron_init }
};

static char				*get_type(const t_json_value *value)
{
	t_json_value	*t;

	t = dict_get(value, "type");
	if (!t || t->type != JSON_STRING)
		return (NULL);
	return (t->value.as_string);
}

bool					init_shape(
	t_shape *shape_out, const t_json_value *value)
{
	size_t	i;
	char	*type;

	assert(shape_out != NULL && value != NULL);
	type = get_type(value);
	if (!type)
		return (false);
	i = 0;
	while (i < sizeof(g_shape_init_map) / sizeof(t_shape_init_kvp))
	{
		if (rt_strcmp(g_shape_init_map[i].key, type) == 0)
		{
			g_shape_init_map[i].fn(shape_out, value);
			return (true);
		}
		i++;
	}
	return (false);
}
