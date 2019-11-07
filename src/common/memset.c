/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   memset.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/06 14:35:56 by nmartins       #+#    #+#                */
/*   Updated: 2019/11/06 14:36:24 by nmartins      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

void	rt_memset(BYTE *buf, BYTE pat, size_t len)
{
	size_t i;

	i = 0;
	while (i < len)
	{
		buf[i] = pat;
		i++;
	}
}
