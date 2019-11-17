/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   uv_texel.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: jandre-d <jandre-d@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/15 13:04:08 by jandre-d       #+#    #+#                */
/*   Updated: 2019/11/17 17:14:15 by jandre-d      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "texture.h"

/*
** key is the filename
*/

t_vec	uv_texel(t_textures *textures, char *key, REAL u, REAL v)
{
	t_texture	*texture;
	t_vec		result;
	t_pixel		texel;
	int			i;
	int			j;

	texture = get_texture(textures, key);
	if (texture == NULL || u < 0 || v > 1)
		return (vec_mk(255, 0, 255));
	i = floor((double)u * (double)texture->img->width);
	j = floor((double)v * (double)texture->img->height);
	texel = img_get_pixel(texture->img, i, j);
	result.x = texel.r;
	result.y = texel.g;
	result.z = texel.b;
	return (result);
}
