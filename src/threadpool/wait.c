/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   wait.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/13 23:06:01 by nmartins       #+#    #+#                */
/*   Updated: 2019/11/15 17:09:04 by nmartins      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <unistd.h>
#include "threadpool.h"

/*
** Wait for the threadpool to be done with all of the current work
** (Blocking)
*/

void	threadpool_wait(t_threadpool *pool)
{
	bool	should_quit;

	should_quit = false;
	while (!should_quit)
	{
		usleep(1);
		pthread_mutex_lock(&pool->lock);
		if (pool->queue == NULL)
		{
			usleep(1000);
			if (pool->queue == NULL)
				should_quit = true;
		}
		pthread_mutex_unlock(&pool->lock);
	}
}
