/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   std_memory.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: nloomans <nloomans@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/07/08 16:08:18 by nloomans       #+#    #+#                */
/*   Updated: 2019/07/08 17:07:13 by nloomans      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "std.h"

void	*std_memset(void *source, int constant, size_t size)
{
	size_t	counter;
	char	*src;

	src = source;
	counter = 0;
	while (counter < size)
	{
		src[counter] = constant;
		counter++;
	}
	return (source);
}

void	*std_memcpy(void *dest, const void *src, size_t n)
{
	size_t		counter;
	const char	*s;
	char		*d;

	s = src;
	d = dest;
	counter = 0;
	while (counter < n)
	{
		d[counter] = s[counter];
		counter++;
	}
	return (dest);
}

int		std_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t					i;
	const unsigned char		*us1;
	const unsigned char		*us2;

	i = 0;
	us1 = s1;
	us2 = s2;
	while (i < n)
	{
		if (us1[i] != us2[i])
			return (us1[i] - us2[i]);
		i++;
	}
	return (0);
}

void	*std_realloc(void *mem, size_t s_len, size_t n_len)
{
	void *out;

	if (!n_len)
		return (NULL);
	out = malloc(n_len);
	if (!out)
		return (NULL);
	std_memcpy(out, mem, s_len > n_len ? n_len : s_len);
	free(mem);
	return (out);
}
