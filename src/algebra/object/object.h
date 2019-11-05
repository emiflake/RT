/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   object.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: pacovali <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/12 18:56:23 by pacovali      #+#    #+#                 */
/*   Updated: 2019/01/23 17:53:36 by pacovali      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECT_H
# define OBJECT_H

# include "../shapes/shape.h"

typedef struct	s_object
{
	t_shape		shape;
}				t_object;

#endif
