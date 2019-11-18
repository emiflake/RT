/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   perlin_noise_free.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: jandre-d <jandre-d@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/18 16:03:47 by jandre-d       #+#    #+#                */
/*   Updated: 2019/11/18 16:05:25 by jandre-d      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "perlin_noise.h"

void perlin_noise_free(t_perlin_noise **p_noise)
{
	free((*p_noise)->hash);
	free(*p_noise);
	*p_noise = NULL;
}
