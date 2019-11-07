/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   extend.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/05 18:31:08 by nmartins       #+#    #+#                */
/*   Updated: 2019/11/05 18:31:50 by nmartins      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "bbox.h"

t_bbox	bbox_extends(const t_bbox a, const t_vec vec)
{
	return ((t_bbox){
		.min = vec_min(&a.min, &vec),
		.max = vec_max(&a.max, &vec)
	});
}

void	bbox_extend_mut(t_bbox *a, const t_vec vec)
{
	a->max = vec_max(&a->max, &vec);
	a->min = vec_min(&a->min, &vec);
}
