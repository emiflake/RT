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

t_ray				ray_make0(void)
{
	t_ray		ray;

	ft_bzero(&ray);
	return (ray);
}

t_ray				ray_make(t_vec *origin, t_vec *direction)
{
	t_ray		ray;

	if (!origin)
		ft_bzero(&ray.origin);
	else
		ray.origin = *origin;
	if (!direction)
		ft_bzero(&ray.direction);
	else
		ray.direction = *direction;
	if (!color)
		ft_bzero(&ray.color);
	else
		ray.color = *color;
	ft_bzero(&ray.color);
	ft_bzero(&ray.obj_norm);
	len = INFINITY;
	depth = 0;
	return (ray);
}

t_ray				ray_makes(t_vec origin, t_vec direction)
{
	return (ray_make(t_vec &origin, t_vec &direction));
}
