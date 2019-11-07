/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/26 16:32:43 by nmartins       #+#    #+#                */
/*   Updated: 2019/11/04 16:52:59 by nmartins      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>
#include <assert.h>

#include "./algebra/shapes/shape.h"
#include "./json/json.h"

#include "./ui/ui.h"

void		set_plane(t_plane *plane)
{
	plane->origin = (t_vec){0, 0, 1};
	plane->normal = (t_vec){0, 0, -1};
}

void		set_sphere(t_sphere *sphere)
{
	sphere->origin = (t_vec){0, 0, 2};
	sphere->radius = 1.0;
}

void		set_disk(t_disk *disk)
{
	set_plane(&disk->plane);
	disk->radius = 1;
}

void		set_square(t_square *square)
{
	set_plane(&square->plane);
	square->side_a = (t_vec){2, 0, 0};
	square->side_b = (t_vec){0, 2, 0};
	square->dot_a = vec_dot(&square->side_a, &square->side_a);
	square->dot_b = vec_dot(&square->side_b, &square->side_b);
}

void		set_triangle(t_triangle *triangle)
{
	t_vec		c;

	set_plane(&square->plane);
	triangle->side_a_b = (t_vec){1, 0, 0};
	triangle->side_a_c = (t_vec){sqrt(2) / 2, sqrt(2) / 2, 0};
	triangle->side_c_a = vec_negate(&triangle->side_a_c);
	triangle->point_c = vec_add(&triangle->plane.origin,&triangle->side_a_c);
	triangle->point_b = vec_add(&triangle->plane.origin, &triangle->side_a_b);
	triangle->side_b_c = vec_sub(&triangle->point_c, &triangle->point_b);
}

void		shape_debug(void)
{
	t_shape 		shape;
	t_sphere		sphere;
	t_plane			plane;
	t_disk			disk;
	t_square		square;
	t_intersection	isect;
	t_ray			ray = ray_make(&(t_vec){0, 0, -1}, &(t_vec){0, 0, 1});

	set_plane(&plane);
	set_sphere(&sphere);
	set_disk(&disk);
	set_square(&square);
	shape.val.as_square = square;
	shape.type = SHAPE_SQUARE;
	isect.t = INFINITY;
	printf("%s", is_intersect(&shape, &ray, &isect) ? "true" : "false");
}

int			main(void)
{
	shape_debug();
/*
	t_app app;
	 const char *example = " { \"key\": [ {\"num\": 42}, {\"hello\": \"world\", \"otherkey\": 69} ], \"owo\": [ { }, { }, 1, 2, 3, 4, \"lol\" ] }";

	t_json_value *val = parse_json(example);

	app_init(&app);
	app_run(&app);

	json_debug(val);
	json_free(val);*/
	return (0);
}
