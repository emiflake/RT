/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   perlin_noise.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: jandre-d <jandre-d@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/18 16:12:02 by jandre-d       #+#    #+#                */
/*   Updated: 2019/11/18 17:05:54 by jandre-d      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "perlin_noise.h"

double perlin_noise(t_perlin_noise *p, double x, double y, double z)
{
	if (p->repeat > 0)
	{
		x = fmod(x, p->repeat);
		y = fmod(y, p->repeat);
		z = fmod(z, p->repeat);
	}
	p->xi = (int)x & 255;
	p->yi = (int)y & 255;
	p->zi = (int)z & 255;

	p->xf = x - (int)x;
	p->yf = y - (int)y;
	p->zf = z - (int)z;

	p->u = p_noise_private_fade(p->xf);
	p->v = p_noise_private_fade(p->yf);
	p->w = p_noise_private_fade(p->zf);

	p->aaa = p->hash[p->hash[p->hash[p->xi] + p->yi] + p->zi];
	p->aba = p->hash[p->hash[p->hash[p->xi] +
	p_noise_private_inc(p, p->yi)] + p->zi];
	p->aab = p->hash[p->hash[p->hash[p->xi] + p->yi] +
	p_noise_private_inc(p, p->zi)];
	p->abb = p->hash[p->hash[p->hash[p->xi] +
	p_noise_private_inc(p, p->yi)] + p_noise_private_inc(p, p->zi)];
	


}
