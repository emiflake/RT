/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/26 16:32:43 by nmartins       #+#    #+#                */
/*   Updated: 2019/11/13 20:56:05 by nmartins      ########   odam.nl         */
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

void		counter(void *stuff)
{
	uint32_t	num;

	num = (uint32_t)(float_rand() * 50000) + 1000000;
	usleep(num);
	(void)stuff;
	ft_printf("Finished some work\n", stuff);
}

int			main(int argc, char **argv)
{
	t_threadpool	*pool;
	t_work			work[1000];

	(void)argc;
	(void)argv;
	pool = threadpool_init(1);
	if (!pool)
		return (1);
	for (size_t i = 0; i < 10; i++)
	{
		work[i].argument = (void*)(i * 42);
		work[i].fn = &counter;
		threadpool_push_work(pool, work[i]);
	}
	sleep(5);
	threadpool_free(pool);
	ft_printf("Freed pool\n");
	sleep(110);
	// t_app app;

	// app_init(&app, argc, argv);
	// app_run(&app);
	return (0);
}
