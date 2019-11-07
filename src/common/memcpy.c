/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   memcpy.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/06 14:36:34 by nmartins       #+#    #+#                */
/*   Updated: 2019/11/06 14:36:57 by nmartins      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

void	rt_memcpy(BYTE *dest, BYTE *res, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		dest[i] = res[i];
		i++;
	}
}
