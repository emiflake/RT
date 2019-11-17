/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   load_texture_file.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: jandre-d <jandre-d@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/15 13:07:43 by jandre-d       #+#    #+#                */
/*   Updated: 2019/11/17 17:24:48 by jandre-d      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "texture.h"

static void			ft_memcpy(void *from, void *to, size_t len)
{
	size_t i;

	i = 0;
	while (i < len)
	{
		((uint8_t *)to)[i] = ((uint8_t *)from)[i];
		i++;
	}
}

static int			ft_strlen(char *str)
{
	size_t i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

static char			*string_append(char *a, char *b)
{
	size_t	l1;
	size_t	l2;
	char	*result;

	l1 = ft_strlen(a);
	l2 = ft_strlen(b);
	result = malloc((l1 + l2 + 1) * sizeof(char));
	if (result == NULL)
		return (NULL);
	ft_memcpy(a, result, l1);
	ft_memcpy(b, result + l1, l2);
	result[l1 + l2] = 0;
	return (result);
}

static t_texture	*texture_load_img(char *name)
{
	t_texture	*result;
	char		*filename;

	result = malloc(sizeof(t_texture));
	if (result == NULL)
		return (NULL);
	filename = string_append("assets/textures/", name);
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
