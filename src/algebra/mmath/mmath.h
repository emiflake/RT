/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   mmath.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/05 16:09:08 by nmartins       #+#    #+#                */
/*   Updated: 2019/11/07 18:03:42 by nmartins      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef MMATH_H
# define MMATH_H

# include "compdef.h"
# include "../vector/vector.h"

typedef struct	s_coordinate_system
{
	t_vec		nt;
	t_vec		nb;
}				t_coordinate_system;

REAL			min(REAL a, REAL b);
REAL			max(REAL a, REAL b);
REAL			clamp(REAL v, REAL v_min, REAL v_max);
REAL			float_rand(void);

void			coord_system_create(const t_vec *n, t_coordinate_system *coord);
t_vec			hemisphere(REAL u, REAL v);

#endif
