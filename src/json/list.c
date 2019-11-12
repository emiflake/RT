/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   list.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/31 19:01:04 by nmartins       #+#    #+#                */
/*   Updated: 2019/11/12 20:33:02 by nmartins      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "json.h"
#include <stdlib.h>
#include <ft_printf.h>

static t_json_value	*mk_list(t_json_list lst)
{
	t_json_value	*val;

	val = (t_json_value*)malloc(sizeof(t_json_value));
	val->type = JSON_LIST;
	val->value.as_list = lst;
	return (val);
}

static void			push_list_node(
	t_json_list_node **root, t_json_value *nv)
{
	t_json_list_node *new_node;

	new_node = (t_json_list_node*)malloc(sizeof(t_json_list_node));
	new_node->next = *root;
	new_node->value = nv;
	*root = new_node;
}

t_json_value		*do_parse_list(const char **str)
{
	t_json_list			list;
	const char			*walker;
	t_json_value		*node;

	list.root = NULL;
	walker = *str;
	skip_whitespace(&walker);
	if (*walker != '[')
		return (NULL);
	walker++;
	skip_whitespace(&walker);
	node = do_parse_json(&walker);
	if (node == NULL)
	{
		skip_whitespace(&walker);
		if (*walker != ']')
			return (NULL);
		*str = &walker[1];
		return (mk_list(list));
	}
	push_list_node(&list.root, node);
	skip_whitespace(&walker);
	while (*walker == ',')
	{
		walker++;
		skip_whitespace(&walker);
		node = do_parse_json(&walker);
		if (!node)
		{
			json_free(mk_list(list));
			return (NULL);
		}
		push_list_node(&list.root, node);
		skip_whitespace(&walker);
	}
	skip_whitespace(&walker);
	// TODO fix leak
	if (*walker != ']')
		return (NULL);
	*str = &walker[1];
	return (mk_list(list));
}
