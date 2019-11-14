/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/26 16:32:43 by nmartins       #+#    #+#                */
/*   Updated: 2019/11/14 14:45:37 by nmartins      ########   odam.nl         */
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

static bool		is_prime(int n)
{
	if (n == 1 || n == 2 || n == 3)
		return (true);
	if (n % 2 == 0)
		return (false);
	for (int i = 2; i < n; i++)
	{
		if (n % i == 0)
			return (false);
	}
	return (true);
}

typedef struct {
	int	num;
	bool is_prime;
} t_task; 

void		thread_work(void *stuff)
{
	t_task *t = stuff;

	t->is_prime = is_prime(t->num);
}

#define PRIMES 1000


int			main(int argc, char **argv)
{
	t_app app;

	app_init(&app, argc, argv);
	app_run(&app);
	return (0);
}
