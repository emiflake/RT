/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   manager.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/13 15:30:39 by nmartins       #+#    #+#                */
/*   Updated: 2019/11/14 12:51:36 by nmartins      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

#include "compdef.h"
#include "threadpool.h"

static int		assign_work(t_worker_node *workers, t_work *work)
{
	t_worker_node	*worker_node;

	(void)debug_work;
	worker_node = workers;
	while (worker_node)
	{
		if (worker_node->worker.work_status == IS_IDLE)
		{
			worker_node->worker.work_status = IS_WORKING;
			worker_node->worker.curr_work = work;
			return (SUCCESS);
		}
		worker_node = worker_node->next;
	}
	return (FAILURE);
}

void			*threadpool_manager(void *threadpool)
{
	t_threadpool	*pool;
	t_work_node		*work_node;
	t_work			*tmp_work;

	pool = (t_threadpool*)threadpool;
	while (pool->pool_status != IS_TERMINATING)
	{
		pthread_mutex_lock(&pool->lock);
		if (pool->queue)
		{
			work_node = pool->queue;
			tmp_work = work_node->work;
			pool->queue = work_node->next;
			free(work_node);
			while (pool->pool_status != IS_TERMINATING)
			{
				usleep(1);
				if (assign_work(pool->workers, work_node->work) == SUCCESS)
					break ;
			}
		}
		pthread_mutex_unlock(&pool->lock);
		usleep(1);
	}
	pthread_exit(NULL);
	return (NULL);
}