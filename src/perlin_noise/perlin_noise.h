/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   perlin_noise.h                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: jandre-d <jandre-d@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/18 14:47:42 by jandre-d       #+#    #+#                */
/*   Updated: 2019/11/20 20:54:14 by nmartins      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PERLIN_NOISE_H
# define PERLIN_NOISE_H
# include <stdbool.h>
# include <stdlib.h>
# include <math.h>
# include "../common/common.h"

typedef struct	s_perlin_noise
{
	int		seed;
	int		depth;
	REAL	amp;
	REAL	fin;
	REAL	div;
	REAL	xa;
	REAL	ya;
}				t_perlin_noise;

void			perlin_noise_free(t_perlin_noise **p_noise);
t_perlin_noise	*perlin_noise_init(int seed, int depth);
REAL			perlin_noise(t_perlin_noise *var, REAL x, REAL y, REAL freq);

#endif
