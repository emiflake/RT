/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   img_set_pixel.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: jandre-d <jandre-d@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/23 20:30:22 by jandre-d       #+#    #+#                */
/*   Updated: 2019/08/25 12:01:44 by jandre-d      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libimg.h"

void	img_set_pixel(t_img *img, t_pixel pixel, int x, int y)
{
	img->pixels[y * img->width + x] = pixel;
}
