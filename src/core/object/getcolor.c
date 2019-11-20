/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   getcolor.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/19 21:20:00 by nmartins       #+#    #+#                */
/*   Updated: 2019/11/20 17:18:03 by nmartins      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "texture/texture.h"
#include "algebra/intersection/intersection.h"
#include "material.h"

t_vec	get_color(
	const t_intersection *isect, const t_material *mat, t_textures *texts)
{
	(void)mat;
	return (mat->color);
}
