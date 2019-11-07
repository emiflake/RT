/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   bbox.h                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/05 16:02:05 by nmartins       #+#    #+#                */
/*   Updated: 2019/11/05 16:05:32 by nmartins      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef BBOX_H
# define BBOX_H

# include "../vector/vector.h"
# include "compdef.h"

typedef struct	s_bbox
{
	t_vec	min;
	t_vec	max;
}				t_bbox;

t_vec	bbox_center(const t_bbox *bbox);

t_bbox	bbox_merges(const t_bbox a, const t_bbox b);
void	bbox_merge_mut(t_bbox *a, const t_bbox b);

t_bbox	bbox_extends(const t_bbox a, const t_vec vec);
void	bbox_extend_mut(t_bbox *a, const t_vec vec);

#endif
