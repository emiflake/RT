/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   img_flip_horizontal.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: jandre-d <jandre-d@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/24 11:55:39 by jandre-d       #+#    #+#                */
/*   Updated: 2019/08/25 13:17:20 by jandre-d      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libimg.h"

void	img_flip_horizontal(t_img *img)
{
	t_pixel temp;
	int		x_off;
	int		y_off;

	if (img->height == 1)
		return ;
	x_off = 0;
	while (x_off < img->width)
	{
		y_off = 0;
		while (y_off < img->height / 2)
		{
			temp = img->pixels[y_off * img->width + x_off];
			img->pixels[y_off * img->width + x_off] =
				img->pixels[(img->height - 1 - y_off) * img->width + x_off];
			img->pixels[(img->height - 1 - y_off) * img->width + x_off] = temp;
			y_off++;
		}
		x_off++;
	}
}
