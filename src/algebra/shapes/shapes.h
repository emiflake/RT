/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   shapes.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: pacovali <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/12 18:56:23 by pacovali      #+#    #+#                 */
/*   Updated: 2019/01/23 17:53:36 by pacovali      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHAPES_H
# define SHAPES_H

# include "../vector/vector.h"
# include "../ray/ray.h"

typedef struct		s_sphere
{
	t_vec			origin;
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
	t_plane			plane;
	t_vec			side_a_c;
	t_vec			side_a_b;
	t_vec			side_b_c;
	t_vec			side_c_a;
	t_vec			point_b;
	t_vec			point_c;
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

typedef struct		s_box
{
	t_vec			center;
	t_vec			size;
	t_vec			up_axis;
	t_vec			right_axis;
	t_vec			front_axis;
	t_vec			min_bound;
	t_vec			max_bound;
}					t_box;
#endif
