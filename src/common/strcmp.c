/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   strcmp.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/12 18:08:06 by nmartins       #+#    #+#                */
/*   Updated: 2019/11/12 18:13:51 by nmartins      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

int		rt_strcmp(const char *a, const char *b)
{
	size_t i;

	i = 0;
	while (a[i] && b[i])
	{
		if (a[i] != b[i])
			return (a[i] - b[i]);
		i++;
	}
	if (a[i] != b[i])
		return (a[i] - b[i]);
	return (0);
}
