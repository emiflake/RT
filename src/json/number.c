/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   number.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/31 14:55:37 by nmartins       #+#    #+#                */
/*   Updated: 2019/11/17 14:33:10 by nmartins      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "json.h"
#include <stdlib.h>
#include <stdio.h>
#include <ft_printf.h>

#include "common/common.h"

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
	val = (double)rt_strtold10(walker, &walker);
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
