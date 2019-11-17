/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   write_byte.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jandre-d <jandre-d@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/24 13:20:29 by jandre-d       #+#    #+#                */
/*   Updated: 2019/08/24 13:22:07 by jandre-d      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libimg.h"

bool	write_byte(int fd, uint8_t byte)
{
	if (write(fd, &byte, 1) != 1)
		return (false);
	return (true);
}
