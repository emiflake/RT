/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_texture.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: jandre-d <jandre-d@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/15 13:05:39 by jandre-d       #+#    #+#                */
/*   Updated: 2019/11/20 21:08:38 by nmartins      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "texture.h"

/*
** key is the filename
*/

t_texture	*get_texture(t_textures *textures, char *key)
{
	t_texture *result;

	pthread_mutex_lock(&textures->lock);
	result = (t_texture *)ash_hashmap_get(textures->hashmap, key);
	if (result == NULL)
		result = load_texture_file(textures, key);
	pthread_mutex_unlock(&textures->lock);
	return (result);
}
