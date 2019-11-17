/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   write_byte_n_times.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: jandre-d <jandre-d@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/24 13:17:34 by jandre-d       #+#    #+#                */
/*   Updated: 2019/08/24 13:22:36 by jandre-d      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libimg.h"

bool	write_byte_n_times(int fd, uint8_t byte, int n)
{
	int i;

	i = 0;
	while (i < n)
	{
		if (write(fd, &byte, 1) != 1)
			return (false);
		i++;
	}
	return (true);
}
