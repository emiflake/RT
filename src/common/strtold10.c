/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   strtold10.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/17 14:26:25 by nmartins       #+#    #+#                */
/*   Updated: 2019/11/17 14:28:38 by nmartins      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

static void			check_sign(char **str, int *sign, int *i)
{
	if (str[0][*i] == '-')
	{
		sign[0] = -1;
		(*i)++;
	}
	else if (str[0][*i] == '+')
	{
		sign[0] = 1;
		(*i)++;
	}
}

static void			get_ldbl(const char *s, int *i, long double *res)
{
	long double	base;

	base = 10;
	*res = 0.0;
	while (rt_isdigit(s[*i]))
	{
		*res = *res * base + (s[*i] - 48);
		(*i)++;
	}
	if (s[*i] == '.')
	{
		(*i)++;
		while (rt_isdigit(s[*i]))
		{
			*res = *res + (s[*i] - 48) / base;
			base *= 10;
			(*i)++;
		}
	}
}

static void			get_exp(const char *s, int *i, int *exp)
{
	int	sign;

	sign = 1;
	*exp = 0;
	if (s[*i] == 'e' || s[*i] == 'E')
	{
		(*i)++;
		if (s[*i] == '-')
			sign = -1;
		if (s[*i] == '-' || s[*i] == '+')
			(*i)++;
		while (rt_isdigit(s[*i]))
		{
			*exp = *exp * 10 + (int)(s[*i] - 48);
			(*i)++;
		}
	}
	*exp *= sign;
}

static void			res_exp(long double *res, int *exp)
{
	while (*exp > 0)
	{
		*res *= 10.0;
		(*exp)--;
	}
	while (*exp < 0)
	{
		*res /= 10.0;
		(*exp)++;
	}
}

long double			rt_strtold10(const char *str, const char **endnum)
{
	int			i;
	long double	res;
	int			exp;
	int			sign;

	i = 0;
	res = 0.0;
	sign = 1;
	while (rt_isspace(str[i]))
		i++;
	check_sign((char**)&str, &sign, &i);
	if (rt_isdigit(str[i]))
		get_ldbl(str, &i, &res);
	get_exp(str, &i, &exp);
	res_exp(&res, &exp);
	if (endnum)
		*endnum = (char*)&str[i];
	if (sign < 0)
		res = -res;
	return (res);
}
