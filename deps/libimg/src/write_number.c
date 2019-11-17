/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   write_number.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: jandre-d <jandre-d@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/17 16:25:19 by jandre-d       #+#    #+#                */
/*   Updated: 2019/11/17 16:37:50 by jandre-d      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libimg.h"

bool	write_number(int fd, int n)
{
	if (n >= 10)
	{
		if (!write_number(fd, n / 10) ||
		!write_byte(fd, n % 10 + '0'))
			return (false);
	}
	if (n <= 9)
	{
		if (!write_byte(fd, n + '0'))
			return (false);
	}
	return (true);
}
