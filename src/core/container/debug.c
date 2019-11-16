/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   debug.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/16 00:16:31 by nmartins       #+#    #+#                */
/*   Updated: 2019/11/16 00:16:42 by nmartins      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "container.h"

void			bvh_debug_c(const t_bvh_node *node, size_t indent)
{
	if (!node)
	{
		ft_printf("%*sNULL\n", indent, "");
	}
	else if (node->object)
	{
		ft_printf("%*sobject type %llu\n", indent, "", node->object->shape.type);
	}
	else
	{
		ft_printf("%*s{\n", indent, "");
		bvh_debug_c(node->left, indent + 4);
		bvh_debug_c(node->right, indent + 4);
		ft_printf("%*s}\n", indent, "");
	}
}

void			bvh_debug(const t_bvh_node *node)
{
	bvh_debug_c(node, 0);
}
