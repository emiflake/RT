/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   quad_equation.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: pacovali <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/12 18:56:23 by pacovali      #+#    #+#                 */
/*   Updated: 2019/01/23 17:53:36 by pacovali      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

# include "shape.h"

bool	quad_eq(REAL *discr, REAL *a, REAL *b)
{
	REAL	square_root;
	REAL	result[2];
	REAL	smallest_root;

	smallest_root = -1.0;
	square_root = sqrt(*discr);
	result[0] = (-(*b) - square_root) / (2 * (*a));
	result[1] = (-(*b) + square_root) / (2 * (*a));
	if (result[0] > 0)
		smallest_root = result[0];
	if (result[1] > 0 && result[1] < result[0])
		smallest_root = result[1];
	return (smallest_root);
}
