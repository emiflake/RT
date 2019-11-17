/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   read_till.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jandre-d <jandre-d@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/15 18:07:05 by jandre-d       #+#    #+#                */
/*   Updated: 2019/11/17 17:07:43 by jandre-d      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libimg.h"

bool	read_till(int fd, char c)
{
	char in;

	while (1)
	{
		if (read(fd, &in, 1) != 1)
			return (false);
		if (in == c)
			return (true);
	}
}
