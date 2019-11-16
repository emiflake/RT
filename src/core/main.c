/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/26 16:32:43 by nmartins       #+#    #+#                */
/*   Updated: 2019/11/16 21:41:23 by nmartins      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>
#include <assert.h>
#include <unistd.h>

#include "./algebra/shapes/shape.h"
#include "./common/common.h"
#include "./algebra/vector/vector.h"
#include "./json/json.h"

#include "./ui/ui.h"
#include "core/camera/camera.h"
#include "core/object/object.h"
#include "threadpool/threadpool.h"
#include "algebra/mmath/mmath.h"

int			main(int argc, char **argv)
{
	t_app app;

	app_init(&app, argc, argv);
	app_run(&app);
	app_free(&app);
	return (0);
}
