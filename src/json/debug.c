/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   debug.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/31 15:04:32 by nmartins       #+#    #+#                */
/*   Updated: 2019/11/01 14:19:58 by nmartins      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "json.h"
#include <stdbool.h>
#include <ft_printf.h>

static void		do_list_debug(const t_json_list *list, size_t indentation)
{
	t_json_list_node	*node;

	if (list->root == NULL)
	{
		ft_printf("%*s[]", indentation, "");
		return ;
	}
	node = list->root;
	ft_printf("%*s[\n", indentation, "");
	while (node)
	{
		do_json_debug(node->value, indentation + 4);
		if (node->next)
			ft_printf(",");
		ft_printf("\n");
		node = node->next;
	}
	ft_printf("%*s]", indentation, "");
}

void			do_json_debug(const t_json_value *val, size_t indentation)
{
	if (val->type == JSON_STRING)
		ft_printf("%*s\"%s\"", indentation, "", val->value.as_string);
	else if (val->type == JSON_NUMBER)
		ft_printf("%*s%lf", indentation, "", val->value.as_number);
	else if (val->type == JSON_LIST)
		do_list_debug(&val->value.as_list, indentation);
	else if (val->type == JSON_DICT)
		do_dict_debug(&val->value.as_dict, indentation);
}

void			json_debug(const t_json_value *val)
{
	do_json_debug(val, 0);
	ft_printf("\n");
}
