/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   number.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/31 14:55:37 by nmartins       #+#    #+#                */
/*   Updated: 2019/11/14 18:39:44 by nmartins      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "json.h"
#include <stdlib.h>
#include <stdio.h>
#include <ft_printf.h>

static bool			is_digit(char c)
{
	return (c >= '0' && c <= '9');
}

static bool			is_space(char c)
{
	return (c == ' ' || c == '\t' || c == '\n');
}

static void        check_sign(char **str, int *sign, int *i)
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

static void        ft_get_ldbl(const char *s, int *i, long double *res)
{
    long double        base;

    base = 10;
    *res = 0.0;
    while (is_digit(s[*i]))
    {
        *res = *res * base + (s[*i] - 48);
        (*i)++;
    }
    if (s[*i] == '.')
    {
        (*i)++;
        while (is_digit(s[*i]))
        {
            *res = *res + (s[*i] - 48) / base;
            base *= 10;
            (*i)++;
        }
    }
}

static void        ft_get_exp(const char *s, int *i, int *exp)
{
    int        sign;

    sign = 1;
    *exp = 0;
    if (s[*i] == 'e' || s[*i] == 'E')
    {
        (*i)++;
        if (s[*i] == '-')
            sign = -1;
        if (s[*i] == '-' || s[*i] == '+')
            (*i)++;
        while (is_digit(s[*i]))
        {
            *exp = *exp * 10 + (int)(s[*i] - 48);
            (*i)++;
        }
    }
    *exp *= sign;
}

static void        ft_res_exp(long double *res, int *exp)
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

long double        ft_strtold10(const char *str, const char **endnum)
{
    int                i;
    long double        res;
    int                exp;
    int                sign;

    i = 0;
    res = 0.0;
    sign = 1;
    while (is_space(str[i]))
        i++;
    check_sign((char**)&str, &sign, &i);
    if (is_digit(str[i]))
        ft_get_ldbl(str, &i, &res);
    ft_get_exp(str, &i, &exp);
    ft_res_exp(&res, &exp);
    if (endnum)
        *endnum = (char*)&str[i];
    if (sign < 0)
        res = -res;
    return (res);
}

static t_json_value		*mk_number(double num)
{
	t_json_value	*val;

	val = (t_json_value*)malloc(sizeof(t_json_value));
	if (!val)
		return (NULL);
	val->type = JSON_NUMBER;
	val->value.as_number = num;
	return (val);
}

t_json_value			*do_parse_number(const char **str)
{
	const char		*walker;
	size_t			i;
	double			val;

	i = 0;
	walker = *str;
	skip_whitespace(&walker);
	if (!((*walker >= '0' && *walker <= '9')
		|| *walker == '-' || *walker == '+'))
		return (NULL);
	val = (double)ft_strtold10(walker, &walker);
	if (*walker == '-' || *walker == '+')
		walker++;
	while (walker[i] >= '0' && walker[i] <= '9')
	{
		if (walker[i] == '\0')
			return (NULL);
		i++;
	}
	*str = &walker[i];
	return (mk_number((double)val));
}
