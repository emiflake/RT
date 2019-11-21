/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   generate_textures.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: jandre-d <jandre-d@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/20 12:06:48 by jandre-d       #+#    #+#                */
/*   Updated: 2019/11/20 21:41:50 by nmartins      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "texture.h"
#include "../perlin_noise/perlin_noise.h"
#include "../../deps/libimg/includes/libimg.h"

static t_texture	*empty_texture(int width, int height)
{
	t_img		*res_img;
	t_texture	*result;

	res_img = img_new(width, height);
	if (res_img == NULL)
		return (NULL);
	result = texture_new();
	if (result == NULL)
	{
		img_destroy(&res_img);
		return (NULL);
	}
	result->img = res_img;
	return (result);
}

static bool			add_texture(t_textures *textures, char *name,
	bool (*func)(t_texture *texture))
{
	t_texture	*tmp_texture;
	char		*tmp_name;

	tmp_texture = empty_texture(2048, 2048);
	if (tmp_texture == NULL)
		return (false);
	ft_asprintf(&tmp_name, "%s", name);
	if (tmp_name == NULL)
	{
		texture_free(&tmp_texture);
		return (false);
	}
	if (!func(tmp_texture))
	{
		texture_free(&tmp_texture);
		free(tmp_name);
		return (false);
	}
	ash_hashmap_insert(textures->hashmap, tmp_name, (void *)tmp_texture);
	return (true);
}

bool				generate_textures(t_textures *textures)
{
	return (add_texture(textures, "internal.lines", generate_texture_lines)
	&& add_texture(textures, "internal.wood", generate_texture_wood)
	&& add_texture(textures, "internal.noise", generate_texture_noise));
}
