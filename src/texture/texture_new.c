/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   texture_new.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: jandre-d <jandre-d@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/20 14:31:51 by jandre-d       #+#    #+#                */
/*   Updated: 2019/11/20 16:46:33 by jandre-d      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "texture.h"

t_texture	*texture_new(void)
{
	t_texture *result;

	result = malloc(sizeof(t_texture));
	if (result == NULL)
		return (NULL);
	result->img = NULL;
	return (result);
}
