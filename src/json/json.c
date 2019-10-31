/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   json.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/31 14:18:47 by nmartins       #+#    #+#                */
/*   Updated: 2019/10/31 15:03:36 by nmartins      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "json.h"
#include <stdlib.h>

t_json_value	*do_parse_json(const char **str)
{
	t_json_value	*ret;

	ret = do_parse_string(str);
	if (ret)
		return (ret);
	ret = do_parse_number(str);
	if (ret)
		return (ret);
// 	ret = do_parse_list(str);
// 	if (ret)
// 		return (ret);
// 	ret = do_parse_dict(str);
// 	if (ret)
// 		return (ret);
// 	return (NULL);
	return (NULL);
}

t_json_value	*parse_json(const char *str)
{
	t_json_value	*val;

	while (*str == '\t' || *str == '\n' || *str == ' ')
		str++;
	val = do_parse_json(&str);
	while (*str == '\t' || *str == '\n' || *str == ' ')
		str++;
	if (*str != '\0')
		return (NULL);
	return (val);
}
