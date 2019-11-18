/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   threadpool.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/13 15:30:44 by nmartins       #+#    #+#                */
/*   Updated: 2019/11/17 14:22:56 by nmartins      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <ft_printf.h>
#include <unistd.h>

#include "compdef.h"
#include "threadpool.h"

static void		allocate_workers(t_worker_node **root, size_t worker_count)
{
	size_t			i;
	t_worker_node	*node;

	*root = NULL;
	i = 0;
	while (i < worker_count)
	{
		node = malloc(sizeof(t_worker_node));
		node->worker.curr_work = NULL;
		node->worker.id = i;
		node->next = *root;
		*root = node;
		i++;
	}
}

static int		start_workers_and_manager(t_threadpool *pool)
{
	t_worker_node	*node;

	if (pthread_create(&pool->manager, NULL, threadpool_manager, pool) != 0)
	{
		ft_printf("Could not start manager thread\n");
		return (FAILURE);
	}
	node = pool->workers;
	while (node)
	{
		node->worker.curr_work = NULL;
		node->worker.work_status = IS_IDLE;
		if (pthread_create(
			&node->worker.thread, NULL, threadpool_worker, &node->worker) != 0)
		{
			ft_printf("Could not start worker thread\n");
			return (FAILURE);
		}
		node = node->next;
	}
	return (SUCCESS);
}

t_threadpool	*threadpool_init(size_t worker_count)
{
	t_threadpool	*pool;

	pool = (t_threadpool*)malloc(sizeof(t_threadpool));
	pool->worker_count = worker_count;
	pool->pool_status = IS_IDLE;
	pool->queue = NULL;
	pool->workers = NULL;
	allocate_workers(&pool->workers, worker_count);
	if (pthread_mutex_init(&pool->lock, NULL))
	{
		ft_printf("Could not initialize mutex\n");
		return (NULL);
	}
	if (start_workers_and_manager(pool) != SUCCESS)
	{
		ft_printf("Could not start workers or manager\n");
		return (NULL);
	}
	return (pool);
}
