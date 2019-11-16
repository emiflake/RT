/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   shapes.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: pacovali <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/12 18:56:23 by pacovali       #+#    #+#                */
/*   Updated: 2019/11/13 01:12:30 by nmartins      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHAPES_H
# define SHAPES_H

# include "../vector/vector.h"
# include "../ray/ray.h"

typedef struct		s_sphere
{
	t_vec			origin;
	t_vec			axis[3];
	REAL			radius;
}					t_sphere;

typedef struct		s_plane
{
	t_vec			origin;
	t_vec			normal;
}					t_plane;

typedef struct		s_disk
{
	t_plane			plane;
	REAL			inner_radius;
	REAL			outer_radius;
}					t_disk;

typedef struct		s_square
{
	t_plane			plane;
	t_vec			side_a;
	REAL			dot_a;
	t_vec			side_b;
	REAL			dot_b;
}					t_square;

typedef struct		s_triangle
{
	t_vec			point[3];
	t_vec			normal[3];
	t_vec			side[2];
}					t_triangle;

typedef struct		s_cylinder
{
	t_vec			origin;
	t_vec			axis;
	REAL			radius;
	REAL			pos_height;
	REAL			neg_height;
}					t_cylinder;

typedef struct		s_cone
{
	t_vec			origin;
	t_vec			axis;
	REAL			angle_deg;
	REAL			cos_angle;
	REAL			pos_height;
	REAL			neg_height;
}					t_cone;

typedef struct		s_cube
{
	t_vec			origin;
	t_vec			size;
	t_vec			axis[3];
	t_square		side[6];
}					t_cube;

typedef struct		s_pyramid
{
	t_vec			origin;
	t_vec			point[4];
	t_triangle		side[8];
	t_square		base;
}					t_pyramid;

typedef struct		s_tetrahedron
{
	t_vec			point[4];
	t_triangle		side[8];
}					t_tetrahedron;

#endif
