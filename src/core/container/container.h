/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   container.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/05 15:59:15 by nmartins       #+#    #+#                */
/*   Updated: 2019/11/07 16:31:37 by nmartins      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTAINER_H
# define CONTAINER_H

# include "core/object/object.h"

/*
** For now, container will be linked list
*/

typedef struct	s_object_container_node
{
	t_object						*val;
	struct s_object_container_node	*next;
}				t_object_container_node;

typedef struct	s_object_container
{
	t_object_container_node	*root;
}				t_object_container;

void			container_push_object(
	t_object_container *container, t_object *obj);

bool	container_is_intersect(
	const t_object_container *container,
	const t_ray *ray, t_intersection *isect);

#endif
