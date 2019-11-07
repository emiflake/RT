/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   clamp.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/05 16:12:00 by nmartins       #+#    #+#                */
/*   Updated: 2019/11/05 16:12:49 by nmartins      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "mmath.h"

REAL	clamp(REAL v, REAL v_min, REAL v_max)
{
	return (min(max(v, v_min), v_max));
}
