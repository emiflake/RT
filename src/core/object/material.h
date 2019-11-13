/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   material.h                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: pacovali <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/12 18:56:23 by pacovali       #+#    #+#                */
/*   Updated: 2019/11/12 16:00:10 by nmartins      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIAL_H
# define MATERIAL_H

typedef struct	s_material
{
	t_vec	color;
	t_vec	emission;
	REAL	blurriness;
	REAL	reflect;
	REAL	ior;
	REAL	transp;
}				t_material;

#endif
