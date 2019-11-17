/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   img_clear.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jandre-d <jandre-d@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/25 16:21:58 by jandre-d       #+#    #+#                */
/*   Updated: 2019/11/17 17:06:59 by jandre-d      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libimg.h"

void	img_clear(t_img *img)
{
	int		i;
	uint8_t	*pixels;

	i = 0;
	pixels = (uint8_t *)img->pixels;
	while (i < img->height * img->width * IMG_BYTES_PER_PIXEL)
	{
		pixels[i] = 0;
		i++;
	}
}
