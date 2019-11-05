/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   vec_negate.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: pacovali <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/12 18:56:23 by pacovali      #+#    #+#                 */
/*   Updated: 2019/01/23 17:53:36 by pacovali      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

t_vec	vec_negate(t_vec *v)
{
	v->x = -v->x;
	v->y = -v->y;
	v->z = -v->z;
	return (*v);
}

t_vec	vec_negates(t_vec v)
{
	return (vec_negate(&v));
}
