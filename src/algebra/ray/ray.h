/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ray.h                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: pacovali <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/12 18:56:23 by pacovali      #+#    #+#                 */
/*   Updated: 2019/01/23 17:53:36 by pacovali      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAY_H
# define RAY_H

# include "../vector/vector.h"
# include <stdlib.h>

typedef struct		s_ray
{
	t_vec			o;
	t_vec			d;
	unsigned char	depth;
	REAL			refration;
	struct s_object	*cur_obj;
}					t_ray;

t_ray				ray_make0();
t_ray				ray_make(t_vec *origin, t_vec *direction);
t_ray				ray_makes(t_vec origin, t_vec direction);

t_ray				ray_duplicate(t_ray *ray);
t_ray				ray_duplicates(t_ray ray);

#endif
