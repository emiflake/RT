/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   mmath.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/05 16:09:08 by nmartins       #+#    #+#                */
/*   Updated: 2019/11/05 16:10:09 by nmartins      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef MMATH_H
# define MMATH_H

# include "compdef.h"

REAL	min(REAL a, REAL b);
REAL	max(REAL a, REAL b);
REAL	clamp(REAL v, REAL v_min, REAL v_max);

#endif
