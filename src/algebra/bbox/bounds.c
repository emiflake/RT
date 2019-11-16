/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   bounds.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/15 19:20:05 by nmartins       #+#    #+#                */
/*   Updated: 2019/11/15 22:05:01 by nmartins      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "bbox.h"

t_vec	bbox_bounds(const t_bbox *bbox, bool want_max)
{
	if (want_max)
		return (bbox->max);
	else
		return (bbox->min);
}
