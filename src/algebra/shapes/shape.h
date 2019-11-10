/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   shape.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: pacovali <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/12 18:56:23 by pacovali       #+#    #+#                */
/*   Updated: 2019/11/07 18:48:06 by nmartins      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHAPE_H
# define SHAPE_H

# include <stdbool.h>
# include "shapes.h"
# include "../point2/point2.h"
# include "../intersection/intersection.h"

typedef struct	s_shape
{
	union {
		t_sphere	as_sphere;
		t_plane		as_plane;
		t_disk		as_disk;
		t_square	as_square;
		t_triangle	as_triangle;
		t_cylinder	as_cylinder;
		t_cone		as_cone;
	}	val;
	enum {
		SHAPE_SPHERE,
		SHAPE_PLANE,
		SHAPE_DISK,
		SHAPE_SQUARE,
		SHAPE_TRIANGLE,
		SHAPE_CYLINDER,
		SHAPE_CONE
	}	type;
}				t_shape;

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

bool				is_triangle_intersect(const t_shape *shape,
									const t_ray *ray, t_intersection *intrs);
void				triangle_intersection(const t_ray *ray,
									t_intersection *intrs);

bool				is_cylinder_intersect(const t_shape *shape,
									const t_ray *ray, t_intersection *intrs);
void				cylinder_intersection(const t_ray *ray,
									t_intersection *intrs);

bool				is_cone_intersect(const t_shape *shape,
									const t_ray *ray, t_intersection *intrs);
void				cone_intersection(const t_ray *ray,
									t_intersection *intrs);

t_point2			quad_eq(REAL discr, REAL a, REAL b);

#endif
