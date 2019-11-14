/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   manager.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/13 15:30:39 by nmartins       #+#    #+#                */
/*   Updated: 2019/11/14 14:39:34 by nmartins      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <assert.h>

#include "compdef.h"
#include "threadpool.h"

static int		assign_work(t_worker_node *workers, t_work *work)
{
	t_worker_node	*worker_node;

	(void)debug_work;
	assert(work != NULL);
	worker_node = workers;
	while (worker_node)
	{
		if (worker_node->worker.work_status == IS_IDLE)
		{
			worker_node->worker.work_status = IS_WORKING;
			worker_node->worker.curr_work = work;
			assert(worker_node->worker.curr_work != NULL);
			assert(worker_node->worker.curr_work->fn != NULL);
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
		if (pool->queue)
		{
			pthread_mutex_lock(&pool->lock);
			work_node = pool->queue;
			tmp_work = work_node->work;
			assert(tmp_work->fn != NULL);
			pool->queue = work_node->next;
			free(work_node);
			pthread_mutex_unlock(&pool->lock);
			while (pool->pool_status != IS_TERMINATING)
			{
				usleep(1);
				if (assign_work(pool->workers, tmp_work) == SUCCESS)
					break ;
			}
		}
		usleep(1);
	}
	pthread_exit(NULL);
	return (NULL);
}