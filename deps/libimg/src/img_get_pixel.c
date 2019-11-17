/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   img_get_pixel.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: jandre-d <jandre-d@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/24 11:46:58 by jandre-d       #+#    #+#                */
/*   Updated: 2019/08/25 12:01:27 by jandre-d      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libimg.h"

t_pixel	img_get_pixel(t_img *img, int x, int y)
{
	return (img->pixels[y * img->width + x]);
}
