/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   debug.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/31 15:04:32 by nmartins       #+#    #+#                */
/*   Updated: 2019/10/31 15:06:33 by nmartins      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "json.h"
#include <ft_printf.h>

void			json_debug(const t_json_value *val)
{
	if (val->type == JSON_STRING)
		ft_printf("\"%s\"", val->value.as_string);
	else if (val->type == JSON_NUMBER)
		ft_printf("%lf", val->value.as_number);
	else
		ft_printf("Unhandled JSON type");
}
