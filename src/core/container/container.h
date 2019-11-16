/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   container.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/05 15:59:15 by nmartins       #+#    #+#                */
/*   Updated: 2019/11/16 21:34:39 by nmartins      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTAINER_H
# define CONTAINER_H

# include "core/object/object.h"
# include "algebra/bbox/bbox.h"
# include "algebra/vector/vector.h"

/*
** Loader linked-list structure pass
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

void			container_free(t_object_container_node *nd);

bool	container_is_intersect(
	const t_object_container *container,
	const t_ray *ray, t_intersection *isect);

/*
** BVH Tree
**
** This section is dedicated to the BVH tree
** and its construction.
*/
typedef struct	s_bvh_node
{
	t_bbox				bounding_box;
	struct s_bvh_node	*right;
	struct s_bvh_node	*left;
	t_object			*object;
}				t_bvh_node;

t_bvh_node		*bvh_construct(t_object_container_node *shapes);
t_bvh_node		*bvh_construct_rec(t_object_container_node *shapes,
	size_t count,
	size_t dimension);
bool			bvh_is_intersect(
	const t_bvh_node *node, const t_ray *ray, t_intersection *isect);
void			bvh_debug(const t_bvh_node *node);
void			bvh_free(t_bvh_node *node);

#endif
