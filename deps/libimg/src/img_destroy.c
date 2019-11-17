/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   img_destroy.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: jandre-d <jandre-d@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/23 11:01:38 by jandre-d       #+#    #+#                */
/*   Updated: 2019/08/23 13:49:44 by jandre-d      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libimg.h"

void	img_destroy(t_img **img)
{
	free((*img)->pixels);
	free(*img);
	*img = NULL;
}
