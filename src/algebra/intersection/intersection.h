/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   intersection.h                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: pacovali <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/12 18:56:23 by pacovali      #+#    #+#                 */
/*   Updated: 2019/01/23 17:53:36 by pacovali      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERSECTION_H
# define INTERSECTION_H

#include "../point2/point2.h"

typedef struct	s_intersection
{
	struct s_object		*obj_ptr;
	REAL				t;
	t_vec				p;
	t_point2			uv;
	t_vec				normal;
}				t_intersection;

#endif
