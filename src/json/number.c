/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   number.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/31 14:55:37 by nmartins       #+#    #+#                */
/*   Updated: 2019/11/12 20:06:22 by nmartins      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "json.h"
#include <stdlib.h>
#include <ft_printf.h>

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

static int				ft_atoi(const char *str)
{
	long long	result;
	int			mag;

	result = 0;
	mag = 1;
	while (*str == ' ' || *str == '\t' || *str == '\n'
		|| *str == '\r' || *str == '\v' || *str == '\f')
		str++;
	if (*str == '+')
		str++;
	else if (*str == '-')
	{
		mag = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		result = result * 10 + (*str - '0');
		str++;
	}
	return (mag * result);
}

t_json_value			*do_parse_number(const char **str)
{
	const char		*walker;
	size_t			i;
	int				val;

	i = 0;
	walker = *str;
	skip_whitespace(&walker);
	if (!((*walker >= '0' && *walker <= '9')
		|| *walker == '-' || *walker == '+'))
		return (NULL);
	val = ft_atoi(walker);
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
