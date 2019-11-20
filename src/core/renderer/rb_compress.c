/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rb_compress.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/17 16:06:45 by nmartins       #+#    #+#                */
/*   Updated: 2019/11/20 17:21:20 by nmartins      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <assert.h>

#include "algebra/point2/point2.h"
#include "realbuffer.h"

static uint32_t	pix(size_t x, size_t y, const t_realbuffer *buf)
{
	t_vec	res;

	res = buf->buf[x + y * buf->width];
	vec_mult_mut_scalar(&res, 1.0 / buf->samples);
	vec_color_clamp_mut(&res);
	return ((uint32_t)res.x << 16 | (uint32_t)res.y << 8 | (uint32_t)res.z);
}

void			rb_compress(const t_realbuffer *buf, SDL_Surface *surf)
{
	size_t	y;
	size_t	x;

	y = 0;
	while (y < (size_t)surf->h)
	{
		x = 0;
		while (x < (size_t)surf->w)
		{
			((uint32_t*)surf->pixels)[y * surf->w + x] = pix(x, y, buf);
			x++;
		}
		y++;
	}
}
