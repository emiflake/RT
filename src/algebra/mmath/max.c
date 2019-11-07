/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   max.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/05 16:10:51 by nmartins       #+#    #+#                */
/*   Updated: 2019/11/05 16:11:11 by nmartins      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "mmath.h"

REAL	max(REAL a, REAL b)
{
	return (a > b ? a : b);
}
