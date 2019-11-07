/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   std_misc.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: nloomans <nloomans@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/07/08 16:42:31 by nloomans       #+#    #+#                */
/*   Updated: 2019/07/08 17:01:30 by nloomans      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "std.h"

int		std_isprint(int c)
{
	return (c >= ' ' && c <= '~');
}

int		std_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

int		std_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		return (c - ('A' - 'a'));
	else
		return (c);
}

int		std_max(int a, int b)
{
	if (a > b)
		return (a);
	else
		return (b);
}

int		std_min(int a, int b)
{
	if (a < b)
		return (a);
	else
		return (b);
}
