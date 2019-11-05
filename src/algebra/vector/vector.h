/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   vector.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/26 13:19:53 by nmartins       #+#    #+#                */
/*   Updated: 2019/10/28 14:19:12 by nmartins      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_H
# define VECTOR_H

# include <math.h>

# define EPS	0.00001

typedef struct	s_vec
{
	REAL x;
	REAL y;
	REAL z;
}				t_vec;

t_vec			vec_adds(const t_vec a, const t_vec b);
t_vec			vec_add(const t_vec *a, const t_vec *b);
void			vec_add_mut(t_vec *a, const t_vec *b);

t_vec			vec_subs(const t_vec a, const t_vec b);
t_vec			vec_sub(const t_vec *a, const t_vec *b);
void			vec_sub_mut(t_vec *a, const t_vec *b);

t_vec			vec_mults(const t_vec a, const t_vec b);
t_vec			vec_mult(const t_vec *a, const t_vec *b);
void			vec_mult_mut(t_vec *a, const t_vec *b);
t_vec			vec_mults_scalar(const t_vec a, REAL scalar);
void			vec_mult_mut_scalar(t_vec *a, REAL scalar);

REAL			vec_dot(const t_vec *a, const t_vec *b);

t_vec			vec_normalizeds(const t_vec a);
t_vec			vec_normalized(const t_vec *a);
void			vec_normalize(t_vec *v);

REAL			vec_length2s(const t_vec a);
REAL			vec_length2(const t_vec *a);
REAL			vec_lengths(const t_vec a);
REAL			vec_length(const t_vec *a);

REAL			vec_distances(const t_vec a, const t_vec b);
REAL			vec_distance(const t_vec *a, const t_vec *b);

t_vec			vec_make0(void);
t_vec			vec_make1(void);
t_vec			vec_mk(REAL x, REAL y, REAL z);

void			vec_debug(const t_vec *v);
void			vec_debugs(const t_vec v);

REAL			vec_angle_rad(t_vec *a, t_vec *b);
REAL			vec_angle_rads(t_vec a, t_vec b);
REAL			vec_angle_degs(t_vec a, t_vec b);
REAL			vec_angle_deg(t_vec *a, t_vec *b);

int				vec_isequal(t_vec *a, t_vec *b);
int				vec_isequals(t_vec a, t_vec b);
int				vec_isnull(t_vec *a);
int				vec_isnulls(t_vec a);

REAL			deg_to_rad(REAL degrees);
REAL			rad_to_deg(REAL radians);

t_vec			vec_cross(t_vec *a, t_vec *b);
t_vec			vec_cross_s(t_vec a, t_vec b);

t_vec			vec_negate(t_vec *v);
t_vec			vec_negates(t_vec v);

t_vec			vec_reflects(t_vec v, t_vec n);
t_vec			vec_reflect(t_vec *v, t_vec *n);

REAL			vec_reflectance(t_vec *vec, t_vec *norm, REAL k1, REAL k2);

t_vec			vec_refracts(t_vec vec, t_vec norm, REAL k1, REAL k2);

#endif
