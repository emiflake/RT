/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rand.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/07 18:02:24 by nmartins       #+#    #+#                */
/*   Updated: 2019/11/07 18:03:29 by nmartins      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <stdlib.h>

#include "mmath.h"

REAL	float_rand(void)
{
	return ((float)rand() / (float)(RAND_MAX));
}
