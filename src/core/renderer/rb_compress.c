/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rb_compress.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/17 16:06:45 by nmartins       #+#    #+#                */
/*   Updated: 2019/11/17 16:14:50 by nmartins      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "algebra/point2/point2.h"
#include "realbuffer.h"

static uint32_t	nearest_pix(double x, double y, const t_realbuffer *buf)
{
	t_vec	res;

	res = buf->buf[(size_t)((x * buf->width) + (y * buf->width * buf->height))];
	return ((uint32_t)res.x << 16 | (uint32_t)res.y << 8 | (uint32_t)res.x);
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
			((uint32_t*)surf->pixels)[y * surf->w + x] = nearest_pix(
				(double)x / (double)surf->w, (double)y / (double)surf->h, buf);
			x++;
		}
		y++;
	}
}
