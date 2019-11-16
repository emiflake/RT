/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   free.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/16 21:32:49 by nmartins       #+#    #+#                */
/*   Updated: 2019/11/16 21:36:51 by nmartins      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "container.h"

void			container_free(t_object_container_node *nd)
{
	if (!nd)
		return ;
	container_free(nd->next);
	free(nd->val);
	free(nd);
}

void			bvh_free(t_bvh_node *node)
{
	if (!node)
		return ;
	if (node->left)
		bvh_free(node->left);
	if (node->right)
		bvh_free(node->right);
	free(node);
}
