/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   hasher.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: emiflake <marvin@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/14 16:37:30 by emiflake       #+#    #+#                */
/*   Updated: 2019/10/31 18:57:17 by nmartins      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>

#include "./ashmap.h"

uint64_t	ash_hash_fnv_64(const void *bytes, size_t len)
{
	unsigned char	*p;
	uint64_t		h;
	size_t			i;

	i = 0;
	h = 14695981039346656037U;
	p = (unsigned char*)bytes;
	while (i < len)
	{
		h = p[i] ^ (h * 1099511628211U);
		i++;
	}
	return (h);
}

uint64_t	ash_hash(const void *bytes, size_t len)
{
	return (ash_hash_fnv_64(bytes, len));
}
