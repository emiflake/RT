/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   util.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/31 19:01:29 by nmartins       #+#    #+#                */
/*   Updated: 2019/10/31 19:58:43 by nmartins      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <ft_printf.h>

static bool	is_space(char c)
{
	return (c == '\t' || c == ' ' || c == '\n');
}

void		skip_whitespace(const char **str)
{
	while (is_space(**str))
		(*str)++;
}
