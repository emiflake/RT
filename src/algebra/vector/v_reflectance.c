/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   reflectance.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: pacovali <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/12 18:56:23 by pacovali      #+#    #+#                 */
/*   Updated: 2019/01/23 17:53:36 by pacovali      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

static REAL		calc_res(REAL *cos_v, REAL *cos_r, REAL *k1, REAL *k2)
{
	REAL	r_orth;
	REAL	r_par;

	r_orth = (*k1 * *cos_v - *k2 * *cos_r) / (*k1 * *cos_v + *k2 * *cos_r);
	r_par = (*k2 * *cos_v - *k1 * *cos_r) / (*k2 * *cos_v + *k1 * *cos_r);
	return ((r_orth * r_orth + r_par * r_par) / 2);
}

REAL			vec_reflectance(t_vec *vec, t_vec *norm, REAL k1, REAL k2)
{
	t_vec	refracted;
	t_vec	neg_norm;
	REAL	cos_v;
	REAL	cos_r;

	vec_normalize(vec);
	vec_normalize(norm);
	neg_norm = vec_negate(norm);
	refracted = vec_refracts(*vec, *norm, k1, k2);
	if (vec_isnull(&refracted))
		return (1);
	cos_v = vec_dot(vec, norm) / vec_dot(vec, vec);
	cos_v = (cos_v < 0) ? -cos_v : cos_v;
	cos_r = vec_dot(&refracted, &neg_norm) / vec_dot(&refracted, &refracted);
	cos_r = (cos_r < 0) ? -cos_r : cos_r;
	return (calc_res(&cos_v, &cos_r, &k1, &k2));
}
