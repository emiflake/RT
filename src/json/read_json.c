/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   read_json.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/06 14:22:53 by nmartins       #+#    #+#                */
/*   Updated: 2019/11/06 15:17:49 by nmartins      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>
#include <stdlib.h>

#include "json.h"

t_json_value	*read_json(const char *filename)
{
	char			*contents;
	t_json_value	*val;

	contents = NULL;
	if (read_file(filename, &contents) != SUCCESS)
	{
		return (NULL);
	}
	else
	{
		val = (parse_json(contents));
		free(contents);
		return (val);
	}
}
