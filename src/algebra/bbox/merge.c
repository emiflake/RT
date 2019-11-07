/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   merge.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/05 16:16:55 by nmartins       #+#    #+#                */
/*   Updated: 2019/11/05 18:30:47 by nmartins      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "bbox.h"

t_bbox	bbox_merges(const t_bbox a, const t_bbox b)
{
	return ((t_bbox){
		.min = vec_min(&a.min, &b.min),
		.max = vec_max(&a.max, &b.max)
	});
}

void	bbox_merge_mut(t_bbox *a, const t_bbox b)
{
	a->max = vec_max(&a->max, &b.max);
	a->min = vec_min(&a->min, &b.min);
}
