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

#include "ray.h"

static void			ft_bzero(void *s, size_t n)
{
	char *ptr;

	ptr = (char*)s;
	while (n > 0)
	{
		n--;
		ptr[n] = '\0';
	}
}

t_ray				ray_make0(void)
{
	t_ray		ray;

	ft_bzero(&ray, sizeof(t_ray));
	return (ray);
}

t_ray				ray_make(t_vec *o, t_vec *d)
{
	t_ray		ray;

	ft_bzero(&ray, sizeof(t_ray));
	if (o)
		ray.o = *o;
	if (d)
		ray.d = *d;
	ray.depth = 0;
	return (ray);
}

t_ray				ray_makes(t_vec origin, t_vec direction)
{
	return (ray_make(&origin, &direction));
}
