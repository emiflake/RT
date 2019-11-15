/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   bounds.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/15 19:20:05 by nmartins       #+#    #+#                */
/*   Updated: 2019/11/15 19:20:35 by nmartins      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "bbox.h"

t_vec	bounds(t_bbox bbox, bool want_max)
{
	if (want_max)
		return (bbox.max);
	else
		return (bbox.min);
}
