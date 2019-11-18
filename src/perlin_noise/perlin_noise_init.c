/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   perlin_noise_init.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: jandre-d <jandre-d@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/18 15:03:09 by jandre-d       #+#    #+#                */
/*   Updated: 2019/11/18 23:39:08 by jandre-d      ########   odam.nl         */
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
	// result->hash = create_lookup_table();
	// if (result->hash == NULL)
	// {
	// 	free(result);
	// 	return (NULL);
	// }
	return (result);
}
