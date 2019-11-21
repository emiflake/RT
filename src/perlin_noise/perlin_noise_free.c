/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   perlin_noise_free.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: jandre-d <jandre-d@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/18 16:03:47 by jandre-d       #+#    #+#                */
/*   Updated: 2019/11/20 20:54:10 by nmartins      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "perlin_noise.h"

void	perlin_noise_free(t_perlin_noise **p_noise)
{
	free(*p_noise);
	*p_noise = NULL;
}
