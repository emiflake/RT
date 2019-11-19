/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   getcolor.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/19 21:20:00 by nmartins       #+#    #+#                */
/*   Updated: 2019/11/19 22:04:35 by nmartins      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "texture/texture.h"
#include "algebra/intersection/intersection.h"
#include "material.h"

t_vec	get_color(
	const t_intersection *isect, const t_material *mat, t_textures *texts)
{
	(void)mat;
	// if (mat->texture != NULL)
	// {
		// ft_printf("mat->texture: <<%s>>\n", mat->texture);
		return (uv_texel(texts, "w.ppm", isect->uv.x, isect->uv.y));
	// }
	// else
		// return (mat->color);
}
