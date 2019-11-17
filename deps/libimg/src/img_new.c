/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   img_new.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: jandre-d <jandre-d@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/23 11:15:31 by jandre-d       #+#    #+#                */
/*   Updated: 2019/08/23 11:30:58 by jandre-d      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libimg.h"

t_img	*img_new(int width, int height)
{
	t_img	*res;

	res = malloc(sizeof(t_img));
	if (res == NULL)
		return (NULL);
	res->height = height;
	res->width = width;
	res->pixels = malloc(IMG_BYTES_PER_PIXEL * width * height);
	if (res->pixels == NULL)
	{
		free(res);
		return (NULL);
	}
	return (res);
}
