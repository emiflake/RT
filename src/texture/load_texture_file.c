/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   load_texture_file.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: jandre-d <jandre-d@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/15 13:07:43 by jandre-d       #+#    #+#                */
/*   Updated: 2019/11/20 19:36:13 by nmartins      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

#include "texture.h"

static t_texture	*texture_load_img(char *name)
{
	t_texture	*result;
	char		*filename;

	result = texture_new();
	if (result == NULL)
		return (NULL);
	ft_asprintf(&filename, "assets/textures/%s", name);
	if (filename != NULL)
		result->img = ppm_file_to_img(filename);
	if (filename == NULL || result->img == NULL)
	{
		ft_printf("cant open/read file \"%s\"\n", filename);
		free(result);
		free(filename);
		return (NULL);
	}
	free(filename);
	return (result);
}

t_texture			*load_texture_file(t_textures *textures, char *name)
{
	t_texture *texture;

	texture = texture_load_img(name);
	if (texture == NULL)
		return (NULL);
	ash_hashmap_insert(textures->hashmap, name, (void *)texture);
	return (texture);
}
