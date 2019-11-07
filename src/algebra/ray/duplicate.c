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

t_ray				ray_duplicate(t_ray *ray)
{
	t_ray		new;

	if (!ray)
	{
		ft_bzero(&new, sizeof(t_ray));
		return (new);
	}
	new.o = ray->o;
	new.d = ray->d;
	new.depth = ray->depth;
	return (new);
}

t_ray				ray_duplicates(t_ray ray)
{
	return (ray_duplicate(&ray));
}
