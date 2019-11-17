/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ppm_fd_atoi.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: jandre-d <jandre-d@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/15 19:38:29 by jandre-d       #+#    #+#                */
/*   Updated: 2019/11/17 17:08:33 by jandre-d      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libimg.h"

static bool	read_char(int fd, char *c)
{
	if (read(fd, c, 1) != 1)
		return (false);
	return (true);
}

bool		ppm_fd_atoi(int fd, int *result)
{
	size_t	i;
	char	c;

	i = 0;
	*result = 0;
	while (1)
	{
		if (read_char(fd, &c) == false ||
		(c == '#' && read_till(fd, '\n') == false))
			return (false);
		if (c >= '0' && c <= '9')
			break ;
	}
	while (1)
	{
		if (!(c >= '0' && c <= '9'))
			break ;
		*result *= 10;
		*result += c - '0';
		if (read_char(fd, &c) == false)
			return (false);
	}
	return (true);
}
