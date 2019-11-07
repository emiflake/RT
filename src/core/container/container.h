/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   container.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/05 15:59:15 by nmartins       #+#    #+#                */
/*   Updated: 2019/11/05 16:08:28 by nmartins      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTAINER_H
# define CONTAINER_H

/*
** Dummy type
*/
struct s_object;

/*
** For now, container will be linked list
*/

typedef struct	s_object_container_node
{
	struct s_object					*val;
	struct s_object_container_node	*next;
}				t_object_container_node;

typedef struct	s_object_container
{
	t_object_container_node	*root;
}				t_object_container;

#endif
