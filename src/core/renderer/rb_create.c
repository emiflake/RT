/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rb_create.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/17 15:38:07 by nmartins       #+#    #+#                */
/*   Updated: 2019/11/17 16:31:31 by nmartins      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "realbuffer.h"

t_realbuffer	*rb_create(size_t w, size_t h)
{
	t_realbuffer	*buf;

	buf = (t_realbuffer*)malloc(sizeof(t_realbuffer));
	if (!buf)
		return (NULL);
	buf->width = w;
	buf->height = h;
	buf->samples = 1;
	buf->buf = malloc(sizeof(t_vec) * (buf->width * buf->height));
	if (!buf->buf)
	{
		free(buf);
		return (NULL);
	}
	rb_clear(buf);
	return (buf);
}
