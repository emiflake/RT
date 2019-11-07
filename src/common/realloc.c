/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   realloc.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/06 14:37:06 by nmartins       #+#    #+#                */
/*   Updated: 2019/11/06 14:43:51 by nmartins      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

#include <stdlib.h>

void	rt_realloc(BYTE **buf, size_t cur_size, size_t new_size)
{
	BYTE *new_mem;

	new_mem = (BYTE*)malloc(new_size);
	if (!new_mem)
	{
		free(*buf);
		*buf = NULL;
	}
	rt_memcpy(new_mem, *buf, cur_size);
	if (cur_size < new_size)
		rt_memset(&new_mem[cur_size], 0, new_size - cur_size);
	free(*buf);
	*buf = new_mem;
}
