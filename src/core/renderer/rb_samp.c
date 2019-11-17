/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rb_samp.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/17 15:49:43 by nmartins       #+#    #+#                */
/*   Updated: 2019/11/17 16:06:27 by nmartins      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <assert.h>

#include "realbuffer.h"

void			rb_inc_sample(t_realbuffer *buf)
{
	buf->samples++;
}

void			rb_add_sample(
	t_realbuffer *buf, size_t x, size_t y, const t_vec *contrib)
{
	assert(x >= 0);
	assert(y >= 0);
	assert(x < buf->width);
	assert(y < buf->height);
	vec_add_mut(&buf->buf[x + buf->height * y], contrib);
}
