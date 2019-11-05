/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   compare.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: pacovali <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/12 18:56:23 by pacovali      #+#    #+#                 */
/*   Updated: 2019/01/23 17:53:36 by pacovali      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

int		vec_isequal(t_vec *a, t_vec *b)
{
	int		res;

	res = 1;
	res *= ((a->x - b->x >= 0) ? a->x - b->x < EPS : a->x - b->x > EPS);
	res *= ((a->y - b->y >= 0) ? a->y - b->y < EPS : a->y - b->y > EPS);
	res *= ((a->z - b->z >= 0) ? a->z - b->z < EPS : a->z - b->z > EPS);
	return (res);
}

int		vec_isequals(t_vec a, t_vec b)
{
	return (vec_isequal(&a, &b));
}

int		vec_isnull(t_vec *a)
{
	int		res;

	res = 1;
	res *= ((a->x >= 0) ? a->x < EPS : a->x > EPS);
	res *= ((a->y >= 0) ? a->y < EPS : a->y > EPS);
	res *= ((a->z >= 0) ? a->z < EPS : a->z > EPS);
	return (res);
}

int		vec_isnulls(t_vec a)
{
	return (vec_isnull(&a));
}
