/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_obj.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/07 16:25:49 by nmartins       #+#    #+#                */
/*   Updated: 2019/11/07 16:31:14 by nmartins      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "core/object/object.h"
#include "container.h"

void			container_push_object(
	t_object_container *container, t_object *obj)
{
	t_object_container_node	*newnode;

	newnode = (t_object_container_node*)malloc(sizeof(t_object_container_node));
	if (!newnode)
		return ;
	newnode->next = container->root;
	newnode->val = obj;
	container->root = newnode;
}
