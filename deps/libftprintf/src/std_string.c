/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   std_string.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: nloomans <nloomans@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/07/08 15:57:51 by nloomans       #+#    #+#                */
/*   Updated: 2019/07/08 16:37:19 by nloomans      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "std.h"

size_t	std_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len] != '\0')
		len++;
	return (len);
}

void	std_strrev(char *str)
{
	int		begin;
	int		end;
	char	tmp;

	begin = 0;
	end = std_strlen(str) - 1;
	while (begin < end)
	{
		tmp = str[begin];
		str[begin] = str[end];
		str[end] = tmp;
		begin++;
		end--;
	}
}

int		std_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (1)
	{
		if (i >= n || (s1[i] == '\0' && s2[i] == '\0'))
			return (0);
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
}

char	*std_strchr(const char *haystack, int needle)
{
	char *walker;

	walker = (char*)haystack;
	while (*walker || *walker == needle)
	{
		if (*walker == needle)
			return (walker);
		walker++;
	}
	return (0);
}
