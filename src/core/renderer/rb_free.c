/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rb_free.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/17 15:49:04 by nmartins       #+#    #+#                */
/*   Updated: 2019/11/17 16:06:04 by nmartins      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "realbuffer.h"

void	rb_free(t_realbuffer *buf)
{
	free(buf->buf);
	free(buf);
}
