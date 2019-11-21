/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   getcolor.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/19 21:20:00 by nmartins       #+#    #+#                */
/*   Updated: 2019/11/21 18:36:24 by nmartins      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "texture/texture.h"
#include "algebra/intersection/intersection.h"
#include "material.h"

t_vec	get_color(
	const t_intersection *isect, const t_material *mat, t_textures *texts)
{
	if (mat->texture)
		return (uv_texel(texts, mat->texture,
			fmod(isect->uv.x / mat->uv.x, 1.0),
			fmod(isect->uv.y / mat->uv.y, 1.0)));
	else
		return (mat->color);
}

t_vec	get_emission(
	const t_intersection *isect, const t_material *mat, t_textures *texts)
{
	if (mat->etexture)
		return (uv_texel(texts, mat->etexture,
			fmod(isect->uv.x / mat->uv.x, 1.0),
			fmod(isect->uv.y / mat->uv.y, 1.0)));
	else
		return (mat->emission);
}
