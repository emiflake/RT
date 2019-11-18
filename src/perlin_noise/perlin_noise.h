/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   perlin_noise.h                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: jandre-d <jandre-d@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/18 14:47:42 by jandre-d       #+#    #+#                */
/*   Updated: 2019/11/18 17:02:15 by jandre-d      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PERLIN_NOISE_H
#define PERLIN_NOISE_H
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>
#include "../common/common.h"

typedef struct	s_perlin_noise
{
	int *hash;
	int repeat;
	int xi;
	int yi;
	int zi;
	double xf;
	double yf;
	double zf;
	double u;
	double v;
	double w;
	int aaa;
	int aba;
	int aab;
	int abb;
	int baa;
	int bba;
	int bab;
	int bbb;
	double x1;
	double x2;
	double y1;
	double y2;
}				t_perlin_noise;

int		p_noise_private_inc(t_perlin_noise *p_noise, int num);
double	p_noise_private_grad(int hash_original, double x, double y, double z);
double	p_noise_private_fade(double t);
double	p_noise_private_lerp(double a, double b, double x);

#endif
