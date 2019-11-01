/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   string.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/31 14:25:33 by nmartins       #+#    #+#                */
/*   Updated: 2019/10/31 14:55:08 by nmartins      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "json.h"
#include "stdlib.h"

static t_json_value		*mk_string(char *str)
{
	t_json_value	*val;

	val = (t_json_value*)malloc(sizeof(t_json_value));
	if (!val)
		return (NULL);
	val->type = JSON_STRING;
	val->value.as_string = str;
	return (val);
}

static char				*json_strndup(const char *str, size_t len)
{
	char	*new_string;
	size_t	i;

	new_string = (char*)malloc(len + 1);
	i = 0;
	while (i < len)
	{
		new_string[i] = str[i];
		i++;
	}
	new_string[i] = '\0';
	return (new_string);
}

t_json_value			*do_parse_string(const char **str)
{
	const char		*walker;
	size_t			i;

	i = 0;
	walker = *str;
	if (*walker != '"')
		return (NULL);
	walker++;
	while (walker[i] != '"')
	{
		if (walker[i] == '\0')
			return (NULL);
		i++;
	}
	*str = &walker[i + 1];
	return (mk_string(json_strndup(walker, i)));
}
