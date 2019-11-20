/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   texture_free.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: jandre-d <jandre-d@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/20 13:43:01 by jandre-d       #+#    #+#                */
/*   Updated: 2019/11/20 14:30:30 by jandre-d      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "texture.h"

void	texture_free(t_texture **texture)
{
	img_destroy(&(*texture)->img);
	free(*texture);
	*texture = NULL;
}
