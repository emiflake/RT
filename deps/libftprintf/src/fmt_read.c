/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fmt_read.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: nloomans <nloomans@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/14 12:22:50 by nloomans       #+#    #+#                */
/*   Updated: 2019/06/14 13:22:31 by nloomans      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fmt.h"

/*
** It's impossble to read a size smaller then int with va_arg, since they are
** automaticly promoted to an int. That's why we read them as an int and then
** do a cast dance.
*/

unsigned long long	intern_read_unsigned_int(t_size size, va_list v)
{
	if (size == E_HH)
		return ((unsigned long long)(unsigned char)va_arg(v, unsigned int));
	else if (size == E_H)
		return ((unsigned long long)(unsigned short)va_arg(v, unsigned int));
	else if (size == E_N)
		return ((unsigned long long)va_arg(v, unsigned int));
	else if (size == E_L)
		return ((unsigned long long)va_arg(v, unsigned long));
	else
		return (va_arg(v, unsigned long long));
}

long long			intern_read_signed_int(t_size size, va_list vlist)
{
	if (size == E_HH)
		return ((long long)(char)va_arg(vlist, int));
	else if (size == E_H)
		return ((long long)(short)va_arg(vlist, int));
	else if (size == E_N)
		return ((long long)va_arg(vlist, int));
	else if (size == E_L)
		return ((long long)va_arg(vlist, long));
	else
		return (va_arg(vlist, long long));
}

long double			intern_read_float(t_size size, va_list vlist)
{
	if (size == E_LL)
		return (va_arg(vlist, long double));
	else
		return ((long double)va_arg(vlist, double));
}
