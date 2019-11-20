/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   generate_texture_noise.c                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jandre-d <jandre-d@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/20 15:48:00 by jandre-d       #+#    #+#                */
/*   Updated: 2019/11/20 16:45:32 by jandre-d      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "texture.h"

bool	generate_texture_noise(t_texture *texture)
{
	int				x;
	int				y;
	float			t;
	t_perlin_noise	*noise;

	x = 0;
	y = 0;
	noise = perlin_noise_init(4, 8);
	while (x < texture->img->width)
	{
		y = 0;
		while (y < texture->img->height)
		{
			t = perlin_noise(noise, x, y, 0.02);
			((uint32_t*)texture->img->pixels)[y * texture->img->width + x] =
				(uint32_t)(255 * t) << 16 |
				(uint32_t)(255 * t) << 8 |
				(uint32_t)(255 - 255 * t);
			y++;
		}
		x++;
	}
	return (true);
}
