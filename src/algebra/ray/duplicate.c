/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   make.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: pacovali <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/12 18:56:23 by pacovali      #+#    #+#                 */
/*   Updated: 2019/01/23 17:53:36 by pacovali      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "rays.h"

t_ray				ray_duplicate(t_ray *ray)
{
	t_ray		new;

	if (!ray)
		return (ft_bzero(&new));
	new.origin = ray->origin;
	new.direct = ray->direct;
	new.obj_norm = ray->obj_norm;
	new.clr = ray->clr;
	new.len = ray->len;
	new.depth = depth;
}

t_ray				ray_duplicates(t_ray ray)
{
	return (ray_duplicate(&ray));
}
