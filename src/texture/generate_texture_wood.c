/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   generate_texture_wood.c                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: jandre-d <jandre-d@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/20 13:39:25 by jandre-d       #+#    #+#                */
/*   Updated: 2019/11/20 21:04:00 by nmartins      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "texture.h"

static uint8_t	lerp(int a, int b, float t)
{
	return (a * (1 - t) + b * t);
}

bool			generate_texture_wood(t_texture *texture)
{
	int				x;
	int				y;
	float			t;
	t_perlin_noise	*noise;

	x = 0;
	noise = perlin_noise_init(4, 8);
	while (x < texture->img->width)
	{
		y = 0;
		while (y < texture->img->height)
		{
			t = (1 + sin(M_PI * (x +
				perlin_noise(noise, x, y, 0.006) * 100) / 14)) / 2;
			((uint32_t*)texture->img->pixels)[y * texture->img->width + x] =
				(uint32_t)(lerp(129, 200, t)) << 16 |
				(uint32_t)(lerp(90, 130, t)) << 8 |
				(uint32_t)(lerp(43, 50, t));
			y++;
		}
		x++;
	}
	perlin_noise_free(&noise);
	return (true);
}
