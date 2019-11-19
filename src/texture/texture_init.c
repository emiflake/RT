/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   texture_init.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: jandre-d <jandre-d@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/15 15:39:47 by jandre-d       #+#    #+#                */
/*   Updated: 2019/11/17 17:13:35 by jandre-d      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "texture.h"

t_textures	*texture_init(void)
{
	t_textures *result;

	result = malloc(sizeof(t_textures));
	if (result == NULL)
		return (NULL);
	result->hashmap = ash_hashmap_new(ash_hash);
	if (result->hashmap == NULL)
	{
		free(result);
		return (NULL);
	}
	return (result);
}