/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   shape.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: pacovali <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/12 18:56:23 by pacovali       #+#    #+#                */
/*   Updated: 2019/11/13 01:10:44 by nmartins      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHAPE_H
# define SHAPE_H

# include "json/json.h"
# include <stdbool.h>
# include "shapes.h"
# include "algebra/bbox/bbox.h"
# include "../point2/point2.h"
# include "../intersection/intersection.h"

typedef struct			s_shape
{
	union {
		t_sphere		as_sphere;
		t_plane			as_plane;
		t_disk			as_disk;
		t_square		as_square;
		t_triangle		as_triangle;
		t_cylinder		as_cylinder;
		t_cone			as_cone;
		t_cube			as_cube;
		t_pyramid		as_pyramid;
		t_tetrahedron	as_tetrahedron;
	}	val;
	enum {
		SHAPE_SPHERE,
		SHAPE_PLANE,
		SHAPE_DISK,
		SHAPE_SQUARE,
		SHAPE_TRIANGLE,
		SHAPE_CYLINDER,
		SHAPE_CONE,
		SHAPE_CUBE,
		SHAPE_PYRAMID,
		SHAPE_TETRAHEDRON
	}	type;
}						t_shape;

typedef void(*t_inter_fn)(const t_ray *ray,
										t_intersection *isect);

void					intersection(
	const t_shape *shape, const t_ray *ray, t_intersection *isect);

typedef bool(*t_is_inter_fn)(
	const t_shape *shape, const t_ray *ray, t_intersection *isect);

bool					is_intersect(
	const t_shape *shape, const t_ray *ray, t_intersection *isect);

bool					is_sphere_intersect(const t_shape *shape,const
									t_ray *ray, t_intersection *intrs);
void					sphere_intersecton(const t_ray *ray,
									t_intersection *intrs);

bool					is_plane_intersect(const t_shape *shape,const
									t_ray *ray, t_intersection *intrs);
void					plane_intersection(const t_ray *ray,
									t_intersection *intrs);

bool					is_disk_intersect(const t_shape *shape,
									const t_ray *ray, t_intersection *intrs);
void					disk_intersection(const t_ray *ray,
									t_intersection *intrs);

bool					is_square_intersect(const t_shape *shape,
									const t_ray *ray, t_intersection *intrs);
void					square_intersection(const t_ray *ray,
									t_intersection *intrs);

bool					is_triangle_intersect(const t_shape *shape,
									const t_ray *ray, t_intersection *intrs);
void					triangle_intersection(const t_ray *ray,
									t_intersection *intrs);

bool					is_cylinder_intersect(const t_shape *shape,
									const t_ray *ray, t_intersection *intrs);
void					cylinder_intersection(const t_ray *ray,
									t_intersection *intrs);

bool					is_cone_intersect(const t_shape *shape,
									const t_ray *ray, t_intersection *intrs);
void					cone_intersection(const t_ray *ray,
									t_intersection *intrs);

bool					is_cube_intersect(const t_shape *shape,
									const t_ray *ray, t_intersection *intrs);
void					cube_intersection(const t_ray *ray,
									t_intersection *intrs);

bool					is_pyramid_intersect(const t_shape *shape,
									const t_ray *ray, t_intersection *intrs);
void					pyramid_intersection(const t_ray *ray,
									t_intersection *intrs);

void					tetrahedron_intersection(const t_ray *ray,
									t_intersection *intrs);
bool					is_tetrahedron_intersect(const t_shape *shape,
									const t_ray *ray, t_intersection *intrs);

t_point2				quad_eq(REAL discr, REAL a, REAL b);

/*
** Initialize objects
*/

typedef bool(*t_init_fn)(
	t_shape *shape_out, const t_json_value *value);

typedef	struct			s_shape_init_kvp
{
	const char	*key;
	t_init_fn	fn;
}						t_shape_init_kvp;

bool					init_shape(
	t_shape *shape_out, const t_json_value *value);

bool					cone_init(
	t_shape *shape_out, const t_json_value *value);

bool					cube_init(
	t_shape *shape_out, const t_json_value *value);

bool					cylinder_init(
	t_shape *shape_out, const t_json_value *value);

bool					disk_init(
	t_shape *shape_out, const t_json_value *value);

bool					plane_init(
	t_shape *shape_out, const t_json_value *value);

bool					pyramid_init(
	t_shape *shape_out, const t_json_value *value);

bool					sphere_init(
	t_shape *shape_out, const t_json_value *value);


bool					square_init(
	t_shape *shape_out, const t_json_value *value);

bool					tetrahedron_init(
	t_shape *shape_out, const t_json_value *value);

bool					triangle_init(
	t_shape *shape_out, const t_json_value *value);

/*
** Auxiliar functions
*/

void	cube_set_sides(
	t_cube *cube);

void					pyramid_normals(
	t_pyramid *pyr);

void					square_set(
	t_square *square, t_vec origin, t_vec point_a, t_vec point_b);

void					square_set_side(
	t_square *square, t_vec *origin, t_vec *side_a, t_vec *side_b);

void					triangle_set(
	t_triangle *tri, t_vec a_pos, t_vec b_pos, t_vec c_pos);

/*
** Moving objects
*/

typedef bool(*t_move_fn)(t_shape *shape, t_vec *direction,
							REAL distance);

bool					move_shape(t_shape *shape, t_vec *direction,
							REAL distance);

bool					cube_move(t_shape *shape, t_vec *direction,
							REAL distance);
bool					cone_move(t_shape *shape, t_vec *direction,
							REAL distance);
bool					cylinder_move(t_shape *shape, t_vec *direction,
							REAL distance);
bool					sphere_move(t_shape *shape, t_vec *direction,
							REAL distance);
bool					plane_move(t_shape *shape, t_vec *direction,
							REAL distance);
bool					square_move(t_shape *shape, t_vec *direction,
							REAL distance);
bool					disk_move(t_shape *shape, t_vec *direction,
							REAL distance);
bool					pyramid_move(t_shape *shape, t_vec *direction,
							REAL distance);
bool					tetrahedron_move(t_shape *shape, t_vec *direction,
							REAL distance);
bool					triangle_move(t_shape *shape, t_vec *direction,
							REAL distance);

/*
** Constructing BBOXs
*/

typedef t_bbox(*t_bbox_fn)(const t_shape *shape);

t_bbox					bbox_construct(const t_shape *shape);
t_bbox					sphere_bbox(const t_shape *shape);
t_bbox					plane_bbox(const t_shape *shape);
t_bbox					square_bbox(const t_shape *shape);
t_bbox					cone_bbox(const t_shape *shape);
t_bbox					cube_bbox(const t_shape *shape);
t_bbox					cylinder_bbox(const t_shape *shape);
t_bbox					disk_bbox(const t_shape *shape);
t_bbox					pyramid_bbox(const t_shape *shape);
t_bbox					tetrahedron_bbox(const t_shape *shape);
t_bbox					triangle_bbox(const t_shape *shape);

#endif
