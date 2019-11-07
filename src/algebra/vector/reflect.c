/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   vec_reflect.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: pacovali <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/12 18:56:23 by pacovali      #+#    #+#                 */
/*   Updated: 2019/01/23 17:53:36 by pacovali      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

t_vec	vec_reflect(t_vec *vec, t_vec *norm)
{
	t_vec	r;

	vec_normalize(norm);
	r = vec_mults_scalar(*norm, -2.0 * vec_dot(norm, vec));
	vec_add_mut(&r, vec);
	return (r);
}

t_vec	vec_reflects(t_vec vec, t_vec norm)
{
	return (vec_reflect(&vec, &norm));
}
