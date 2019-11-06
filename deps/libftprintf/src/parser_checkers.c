/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parser_checkers.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/26 18:57:33 by nmartins       #+#    #+#                */
/*   Updated: 2019/07/08 15:51:14 by nloomans      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <assert.h>
#include <stddef.h>
#include "std.h"
#include "token.h"
#include "parser.h"

int			is_conversion_specification(const char *stream)
{
	assert(stream != NULL);
	return (*stream == '%');
}

int			is_color_specification(const char *stream)
{
	assert(stream != NULL);
	return (stream[0] == '%' && stream[1] == '{');
}
