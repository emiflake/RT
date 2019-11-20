/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   perlin_noise_init.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: jandre-d <jandre-d@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/18 15:03:09 by jandre-d       #+#    #+#                */
/*   Updated: 2019/11/20 16:38:13 by jandre-d      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "perlin_noise.h"

t_perlin_noise	*perlin_noise_init(int seed, int depth)
{
	t_perlin_noise *result;

	result = malloc(sizeof(t_perlin_noise));
	if (result == NULL)
		return (NULL);
	result->seed = seed;
	result->depth = depth;
	return (result);
}
