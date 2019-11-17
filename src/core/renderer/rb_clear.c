/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rb_clear.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/17 15:45:52 by nmartins       #+#    #+#                */
/*   Updated: 2019/11/17 16:31:48 by nmartins      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>
#include <assert.h>

#include "realbuffer.h"

void			rb_clear(t_realbuffer *buf)
{
	size_t	i;

	i = 0;
	while (i < buf->height * buf->width)
	{
		assert(buf->buf);
		buf->buf[i].x = 0.0;
		buf->buf[i].y = 0.0;
		buf->buf[i].z = 0.0;
		i++;
	}
}
