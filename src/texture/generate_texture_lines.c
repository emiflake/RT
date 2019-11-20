/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   generate_texture_lines.c                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jandre-d <jandre-d@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/20 13:34:14 by jandre-d       #+#    #+#                */
/*   Updated: 2019/11/20 16:12:50 by jandre-d      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "texture.h"

bool	generate_texture_lines(t_texture *texture)
{
	int		x;
	int		y;
	float	t;

	x = 0;
	y = 0;
	while (x < texture->img->width)
	{
		y = 0;
		while (y < texture->img->height)
		{
			t = (1 + sin(M_PI * y / 14)) / 2;
			((uint32_t*)texture->img->pixels)[y * texture->img->width + x] =
				(uint32_t)(255 - 255 * t) << 16 |
				(uint32_t)(255 * t) << 8 |
				(uint32_t)(255 * t);
			y++;
		}
		x++;
	}
	return (true);
}
