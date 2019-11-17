/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   is.c                                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/17 14:24:35 by nmartins       #+#    #+#                */
/*   Updated: 2019/11/17 14:24:48 by nmartins      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

bool			rt_isdigit(char c)
{
	return (c >= '0' && c <= '9');
}

bool			rt_isspace(char c)
{
	return (c == ' ' || c == '\t' || c == '\n');
}
