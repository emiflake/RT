/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   v3_refract.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: pacovali <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/12 18:56:23 by pacovali      #+#    #+#                 */
/*   Updated: 2019/01/23 17:53:36 by pacovali      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

t_vec	vec_refracts(t_vec vec, t_vec norm, REAL k1, REAL k2)
{
	REAL	ratio;
	REAL	cos_v;
	REAL	cos_r;
	REAL	sin_r2;

	ratio = k1 / k2;
	vec_normalize(&norm);
	cos_v = -vec_dot(&norm, &vec);
	sin_r2 = ratio * ratio * (1.0 - (cos_v * cos_v));
	if (sin_r2 > 1)
		return (vec_make0());
	cos_r = sqrt(1.0 - sin_r2);
	return (vec_adds(vec_mults_scalar(vec, ratio), \
					vec_mults_scalar(norm, (ratio * cos_v - cos_r))));
}
