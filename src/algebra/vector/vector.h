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

# include "../../compdef.h"

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

double			vec_dot(const t_vec *a, const t_vec *b);

t_vec			vec_normalizeds(const t_vec a);
t_vec			vec_normalized(const t_vec *a);
void			vec_normalize(t_vec *v);

double			vec_length2s(const t_vec a);
double			vec_length2(const t_vec *a);
double			vec_lengths(const t_vec a);
double			vec_length(const t_vec *a);

double			vec_distances(const t_vec a, const t_vec b);
double			vec_distance(const t_vec *a, const t_vec *b);

t_vec			vec_make1(REAL r);
t_vec			vec_mk(REAL x, REAL y, REAL z);

void			vec_debug(const t_vec *v);
void			vec_debugs(const t_vec v);

#endif
