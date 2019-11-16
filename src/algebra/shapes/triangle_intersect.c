/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   square_intersect.c                                           :+:    :+:  */
/*                                                     +:+                    */
/*   By: pacovali <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/01 00:42:00 by pacovali      #+#    #+#                 */
/*   Updated: 2019/01/01 00:42:01 by pacovali      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "shape.h"
#include <stdio.h>

void	triangle_intersection(const t_ray *ray, t_intersection *intrs)
{
	(void)intrs;
	(void)ray;
}

static void		set_intersection(t_triangle triangle, t_vec uvt,
						t_intersection *intrs, const t_ray *ray)
{
	t_vec	tmp[3];

	tmp[0] = vec_mults_scalar(triangle.normal[0], 1 - uvt.x - uvt.y);
	tmp[1] = vec_mults_scalar(triangle.normal[1], uvt.x);
	tmp[2] = vec_mults_scalar(triangle.normal[2], uvt.y);
	vec_add_mut(&tmp[1], &tmp[2]);
	vec_add_mut(&tmp[0], &tmp[1]);
	intrs->normal = vec_normalized(&tmp[0]);
	intrs->t = uvt.z;
	tmp[0] = vec_mults_scalar(ray->d, intrs->t);
	intrs->p = vec_add(&ray->o, &tmp[0]);
	intrs->uv.x = uvt.x;
	intrs->uv.y = uvt.y;
}

bool			is_triangle_intersect(const t_shape *shape, const t_ray *ray,
							t_intersection *intrs)
{
	t_vec		orthogonal_vector;
	t_vec		distance;
	t_vec		uvt;
	REAL		det;

	orthogonal_vector = vec_cross(&ray->d, &shape->val.as_triangle.side[1]);
	det = vec_dot(&shape->val.as_triangle.side[0], &orthogonal_vector);
	if ((det < 0 && -det < EPS) || det < EPS)
		return (false);
	det = 1 / det;
	distance = vec_sub(&ray->o, &shape->val.as_triangle.point[0]);
	uvt.x = vec_dot(&distance, &orthogonal_vector) * det;
	if (uvt.x < 0 || uvt.x > 1.0)
		return (false);
	orthogonal_vector = vec_cross(&distance, &shape->val.as_triangle.side[0]);
	uvt.y = vec_dot(&ray->d, &orthogonal_vector) * det;
	if (uvt.y < 0 || (uvt.x + uvt.y) > 1.0)
		return (false);
	uvt.z = vec_dot(&shape->val.as_triangle.side[1], &orthogonal_vector) * det;
	if (uvt.z < 0 || uvt.z > intrs->t)
		return (false);
	set_intersection(shape->val.as_triangle, uvt, intrs, ray);
	return (true);
}

/*
bool			is_triangle_intersect(const t_shape *shape, const t_ray *ray,
		t_intersection *intrs)
{
	t_vec	pvec = vec_cross(&ray->d, &shape->val.as_triangle.side[1]);
	REAL	det = vec_dot(&shape->val.as_triangle.side[0], &pvec);
	if ((det < 0 && -det < EPS) || det < EPS)
		return (false);
	REAL inv_det = 1 / det;
	t_vec	tvec = vec_sub(&ray->o, &shape->val.as_triangle.point[0]);
	REAL	u = vec_dot(&tvec, &pvec) * inv_det;
	if (u < 0 || u > 1.0)
		return (false);
	t_vec	qvec = vec_cross(&tvec, &shape->val.as_triangle.side[0]);
	REAL v = vec_dot(&ray->d, &qvec) * inv_det;
	if (v < 0 || v + u > 1.0)
		return (false);
	REAL	t = vec_dot(&shape->val.as_triangle.side[1], &qvec) * inv_det;
	if (t <= 0 || t > intrs->t)
		return (false);
	t_vec tmp = vec_mults_scalar(ray->d, t);
	intrs->p = vec_add(&ray->o, &tmp);
	intrs->t = t;
	t_vec 	tmp1 = vec_mults_scalar(shape->val.as_triangle.normal[0], 1 - u - v);
	t_vec 	tmp2 = vec_mults_scalar(shape->val.as_triangle.normal[1], u);
	t_vec 	tmp3 = vec_mults_scalar(shape->val.as_triangle.normal[2], v);
	t_vec	tmp4 = vec_add(&tmp1, &tmp2);
	vec_add_mut(&tmp4, &tmp3);
	intrs->normal = tmp4;
	return (true);
}
*/
/*
bool			is_triangle_intersect(const t_shape *shape, const t_ray *ray,
					t_intersection *intrs)
{
	t_shape				shape2;
	t_plane				plane;
	const t_triangle	*triangle;
	t_vec				intrs_vecs[6];
	t_intersection 		tmp_intrs;

	exit(!!printf("got here\n"));
	triangle = &(shape->val.as_triangle);
	plane.normal = triangle->normal[0];
	plane.origin = triangle->point[0];
	shape2.val.as_plane = plane;
	tmp_intrs = *intrs;
	exit(!!printf("got here\n"));
	printf("%.2f %.2f %.2f \n", triangle->normal[0].x, triangle->normal[0].y, triangle->normal[0].z);
	if (is_plane_intersect(&shape2, ray, intrs))
	{
		intrs_vecs[0] = vec_sub(&intrs->p, &triangle->point[0]);
		intrs_vecs[1] = vec_sub(&intrs->p, &triangle->point[1]);
		intrs_vecs[2] = vec_sub(&intrs->p, &triangle->point[2]);
		intrs_vecs[3] = vec_cross(&triangle->side[0], &intrs_vecs[0]);
		intrs_vecs[4] = vec_cross(&triangle->side[1], &intrs_vecs[1]);
		intrs_vecs[5] = vec_cross(&triangle->side[2], &intrs_vecs[2]);
		if (vec_dot(&intrs_vecs[3], &triangle->normal[0]) >= 0 &&
			vec_dot(&intrs_vecs[4], &triangle->normal[0]) >= 0 &&
			vec_dot(&intrs_vecs[5], &triangle->normal[0]) >= 0)
			return (true);
		exit(!!printf("got here\n"));
		*intrs = tmp_intrs;
	}
	return (false);
}
*/
