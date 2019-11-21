/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   material.h                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: pacovali <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/12 18:56:23 by pacovali       #+#    #+#                */
/*   Updated: 2019/11/20 21:26:39 by nmartins      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIAL_H
# define MATERIAL_H

# include "refration.h"

typedef struct	s_material
{
	t_vec		color;
	char		*texture;
	char		*etexture;
	t_vec		emission;
	bool		is_parallel;
	REAL		blurriness;
	REAL		reflective;
	REAL		refraction;
	REAL		transparent;
	t_point2	uv;
}				t_material;

struct s_textures;

t_vec			get_color(
	const t_intersection *isect,
	const t_material *mat, struct s_textures *texts);

t_vec	get_emission(
	const t_intersection *isect, const t_material *mat, struct s_textures *texts);

#endif
