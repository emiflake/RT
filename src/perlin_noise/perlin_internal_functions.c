/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   perlin_internal_functions.c                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jandre-d <jandre-d@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/18 16:24:54 by jandre-d       #+#    #+#                */
/*   Updated: 2019/11/18 16:49:29 by jandre-d      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "perlin_noise.h"

/*
** inc function
** increment the numbers to make sure that the noise still repeats
*/

int		p_noise_private_inc(t_perlin_noise *p_noise, int num) {
	num++;
	if (p_noise->repeat > 0)
		num %= p_noise->repeat;
	return num;
}

/*
** grad function
** conver lower 4 bots of the hash into 12 gradient directions
*/

double	p_noise_private_grad(int hash_original, double x, double y, double z)
{
	double result;
	int hash;
	double u;
	double v;

	result = 0;
	hash = hash_original & 15;
	u = hash < 8 ? x : y;
	if (hash < 4)
		v = y;
	else if (hash == 12 || hash == 14)
		v = x;
	else
		v = z;
	result += (hash & 1) == 0 ? u : -u;
	result += (hash & 2) == 0 ? v : -v;
	return (result);
}

/*
** fade function
** use this value to "ease" coordinate values toward intergral values
** to smooth the final output
** 6t^5 - 15t^4 + 10t^3
*/

double	p_noise_private_fade(double t)
{
	return (t * t * t * (t * (t * 6 - 15) + 10));
}

double	p_noise_private_lerp(double a, double b, double x)
{
	return (a + x * (b - a));	
}
