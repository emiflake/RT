/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   center.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/05 16:13:41 by nmartins       #+#    #+#                */
/*   Updated: 2019/11/05 16:15:51 by nmartins      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "bbox.h"
#include "../vector/vector.h"

t_vec	bbox_center(const t_bbox *bbox)
{
	return ((t_vec){
		(bbox->max.x + bbox->min.x) / 2,
		(bbox->max.y + bbox->min.y) / 2,
		(bbox->max.z + bbox->min.z) / 2
	});
}
