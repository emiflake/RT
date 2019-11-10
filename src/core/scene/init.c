/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/07 16:50:22 by nmartins       #+#    #+#                */
/*   Updated: 2019/11/07 19:46:17 by nmartins      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"
#include <math.h>

void		set_sphere(t_sphere *sphere)
{
	sphere->origin = (t_vec){0, 0, 2};
	sphere->radius = 1.0;
}

void		set_plane(t_plane *plane)
{
	plane->origin = (t_vec){0, -1, 0};
	plane->normal = (t_vec){0, 1, 0};
}

void		set_square(t_square *square)
{
	set_plane(&square->plane);
	square->side_a = (t_vec){0, 0, 3};
	square->side_b = (t_vec){3, 0, 0};
	square->dot_a = vec_dot(&square->side_a, &square->side_a);
	square->dot_b = vec_dot(&square->side_b, &square->side_b);
}

void		set_disk(t_disk *disk)
{
	set_plane(&disk->plane);
	disk->outer_radius = 1;
	disk->inner_radius = 0.5;
}

void		set_triangle(t_triangle *triangle)
{
	triangle->plane.origin = (t_vec){-0.5, 0, 1.5};
	triangle->plane.normal = (t_vec){0, 0, 1};
	triangle->side_a_c = (t_vec){0.5, 0.866, 0};
	triangle->side_a_b = (t_vec){1, 0, 0};
	triangle->point_b = vec_add(&triangle->plane.origin, &triangle->side_a_b);
	triangle->point_c = vec_add(&triangle->plane.origin, &triangle->side_a_c);
	triangle->side_b_c = vec_sub(&triangle->point_c, &triangle->point_b);
	triangle->side_c_a = vec_negates(triangle->side_a_c);
}

void		set_cylinder(t_cylinder *cylinder)
{
	cylinder->origin = (t_vec){-0.5, 0.5, -1};
	cylinder->axis = (t_vec){0, 0.866, -0.5};
	vec_normalize(&cylinder->axis);
	cylinder->radius = 1;
	cylinder->pos_height = 0.5;
	cylinder->neg_height = 0;
}

void		set_cone(t_cone *cone)
{
	cone->origin = (t_vec){0, 0, 0};
	cone->axis = (t_vec){0, 0.866, 0.5};
	vec_normalize(&cone->axis);
	cone->angle_deg = 45;
	cone->cos_angle = cos(deg_to_rad(cone->angle_deg));
	cone->pos_height = 1.0;
	cone->neg_height = 0.5;
}


t_object	*make_object(void)
{
	t_object		*obj;

	obj = malloc(sizeof(t_object));
	if (!obj)
		return (NULL);
	return (obj);
}

void	scene_init(t_scene *scene)
{
	scene->obj_container.root = NULL;
	scene->camera = (t_camera){
		.origin = (t_vec){0, 1, -5.9},
		.rotation = (t_vec){0, 0, 0},
		.fov = 45,
	};
	t_object	*obj;
	
	obj = make_object();
	obj->shape.type = SHAPE_SPHERE;
	obj->material.color = vec_mk(0, 0, 0);//
	obj->material.emission = vec_mk(0, 0, 0);//vec_mk(25, 25, 25);
	set_sphere(&obj->shape.val.as_sphere);
	obj->shape.val.as_sphere.origin = (t_vec){1, 2, -1};
	container_push_object(&scene->obj_container, obj);
	
	obj = make_object();
	obj->shape.type = SHAPE_SPHERE;
	obj->material.color = vec_mk(0,0,0);
	obj->material.emission = vec_mk(0, 0, 0);//vec_mk(25,5,15);
	set_sphere(&obj->shape.val.as_sphere);
	obj->shape.val.as_sphere.origin = (t_vec){1, -1, 3};
	obj->shape.val.as_sphere.radius = 0.5;
	container_push_object(&scene->obj_container, obj);
	
	obj = make_object();
	obj->shape.type = SHAPE_SPHERE;
	obj->material.color = vec_mk(0,0,0);
	obj->material.emission = vec_mk(0, 0, 0);
	set_sphere(&obj->shape.val.as_sphere);
	obj->shape.val.as_sphere.origin = (t_vec){-1, 0, 4};
	container_push_object(&scene->obj_container, obj);
	
	obj = make_object();
	obj->shape.type = SHAPE_PLANE;
	obj->material.color = vec_mk(0, 0, 100);
	obj->material.emission = vec_mk(0, 0, 0);
	obj->shape.val.as_plane.origin = (t_vec){0, 3, 0};
	obj->shape.val.as_plane.normal = (t_vec){0, -1, 0};
	container_push_object(&scene->obj_container, obj);

	obj = make_object();
	obj->shape.type = SHAPE_PLANE;
	obj->material.color = vec_mk(0, 0, 0);
	obj->material.emission = vec_mk(0, 0, 0);
	obj->shape.val.as_plane.origin = (t_vec){0, -1, 0};
	obj->shape.val.as_plane.normal = (t_vec){0, 1, 0};
	container_push_object(&scene->obj_container, obj);

	obj = make_object();
	obj->shape.type = SHAPE_PLANE;
	obj->material.color = vec_mk(0, 0, 0);
	obj->material.emission = vec_mk(0, 0, 0);//vec_mk(25, 25, 0);
	obj->shape.val.as_plane.origin = (t_vec){-2, 0, 0};
	obj->shape.val.as_plane.normal = (t_vec){1, 0, 0};
	container_push_object(&scene->obj_container, obj);

	obj = make_object();
	obj->shape.type = SHAPE_PLANE;
	obj->material.color = vec_mk(0, 0, 100);
	obj->material.emission = vec_mk(0, 0, 0);//vec_mk(25, 0, 25);
	obj->shape.val.as_plane.origin = (t_vec){2, 0, 0};
	obj->shape.val.as_plane.normal = (t_vec){-1, 0, 0};
	container_push_object(&scene->obj_container, obj);

	obj = make_object();
	obj->shape.type = SHAPE_PLANE;
	obj->material.color = vec_mk(0, 0, 100);
	obj->material.emission = vec_mk(0, 0, 0);//vec_mk(0, 25, 25);
	obj->shape.val.as_plane.origin = (t_vec){0, 0, 5};
	obj->shape.val.as_plane.normal = (t_vec){0, 0, -1};
	container_push_object(&scene->obj_container, obj);

	obj = make_object();
	obj->shape.type = SHAPE_PLANE;
	obj->material.color = vec_mk(0, 0, 100);
	obj->material.emission = vec_mk(0, 0, 0);
	obj->shape.val.as_plane.origin = (t_vec){0, 0, -6};
	obj->shape.val.as_plane.normal = (t_vec){0, 0, 1};
	container_push_object(&scene->obj_container, obj);

	obj = make_object();
	obj->shape.type = SHAPE_SQUARE;
	obj->material.color = vec_make0();
	obj->material.emission = vec_mk(255, 255, 255);
	set_square(&obj->shape.val.as_square);
	obj->shape.val.as_square.plane.origin = (t_vec){-1.5, 2.99, 2};
	obj->shape.val.as_square.plane.normal = (t_vec){0, -1, 0};
	container_push_object(&scene->obj_container, obj);
	
	obj = make_object();
	obj->shape.type = SHAPE_DISK;
	obj->material.color = vec_make0();
	obj->material.emission = vec_mk(0, 0, 0);//vec_mk(0, 25, 0);
	set_disk(&obj->shape.val.as_disk);
	obj->shape.val.as_disk.plane.origin = (t_vec){-1, 2, 4};
	obj->shape.val.as_disk.plane.normal = (t_vec){-0.0346, 0.0346, 0.0346};
	container_push_object(&scene->obj_container, obj);
	
	/*obj = make_object();
	obj->shape.type = SHAPE_TRIANGLE;
	obj->material.color = vec_make0();
	obj->material.emission = vec_mk(255, 255, 255);
	set_triangle(&obj->shape.val.as_triangle);
	container_push_object(&scene->obj_container, obj);*/
	
	obj = make_object();
	obj->shape.type = SHAPE_CYLINDER;
	obj->material.color = vec_make0();
	obj->material.emission = vec_mk(0, 0, 0);
	set_cylinder(&obj->shape.val.as_cylinder);
	container_push_object(&scene->obj_container, obj);
	
	obj = make_object();
	obj->shape.type = SHAPE_CONE;
	obj->material.color = vec_make0();
	obj->material.emission = vec_mk(0, 0, 0);
	set_cone(&obj->shape.val.as_cone);
	obj->shape.val.as_cone.axis = (t_vec){1, 1, -1};
	vec_normalize(&obj->shape.val.as_cone.axis);
	obj->shape.val.as_cone.origin = (t_vec){-0.5, 1.5, 0};
	container_push_object(&scene->obj_container, obj);
	
}
