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
# include "shapes.h"
# include "../intersection/intersection.h"

typedef struct	s_shape
{
	union {
		t_sphere	as_sphere;
		t_plane		as_plane;
		t_disk		as_disk;
		t_square	as_square;
	}	val;
	enum {
		SHAPE_SPHERE, SHAPE_PLANE, SHAPE_DISK, SHAPE_SQUARE
	}	type;
}				t_shape;

typedef struct	s_object
{
	t_shape		shape;
}				t_object;

typedef void(*t_inter_fn)(const t_ray *ray, t_intersection *isect);

void			intersection(
	const t_shape *shape, const t_ray *ray, t_intersection *isect);

typedef bool(*t_is_inter_fn)(
	const t_shape *shape, const t_ray *ray, t_intersection *isect);

bool			is_intersect(
	const t_shape *shape, const t_ray *ray, t_intersection *isect);

bool				is_sphere_intersect(const t_shape *shape,const  t_ray *ray,
									t_intersection *intrs);
void				sphere_intersecton(const t_ray *ray, t_intersection *intrs);

bool				is_plane_intersect(const t_shape *shape,const  t_ray *ray,
									t_intersection *intrs);
void				plane_intersection(const t_ray *ray,
									t_intersection *intrs);

bool				is_disk_intersect(const t_shape *shape, const t_ray *ray,
									t_intersection *intrs);
void				disk_intersection(const t_ray *ray, t_intersection *intrs);

bool				is_square_intersect(const t_shape *shape, const t_ray *ray,
									t_intersection *intrs);
void				square_intersection(const t_ray *ray,
									t_intersection *intrs);

bool				quad_eq(REAL *discr, REAL *a, REAL *b);

#endif
