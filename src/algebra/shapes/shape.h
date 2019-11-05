/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   shape.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: pacovali <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/12 18:56:23 by pacovali      #+#    #+#                 */
/*   Updated: 2019/01/23 17:53:36 by pacovali      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHAPE_H
# define SHAPE_H

# include <stdbool.h>

typedef struct	s_shape
{
	union {
		t_sphere	as_sphere;
	}	val;
	enum {
		SHAPE_SPHERE,
	}	type;
}				t_shape;

void			calc_normal(const t_shape *shape, t_intersection *isect);

typedef bool(t_inter_fn *)(const t_ray *ray, const t_shape *shape, t_intersection *isect);

bool			intersect(
	const t_ray *ray, const t_shape *shape, t_intersection *isect);

#endif
