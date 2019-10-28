/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/26 16:32:43 by nmartins       #+#    #+#                */
/*   Updated: 2019/10/28 14:20:26 by nmartins      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

#include "./algebra/vector/vector.h"

int	main(void)
{
	t_vec	v = vec_make1(42);

	v = vec_adds(v, vec_mk(1, 2, 3));
	v = vec_mults(v, vec_mk(0.5, 1.0, 0.25));

	vec_debug(&v);
	return (0);
}
