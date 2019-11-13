/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   threadpool.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/13 15:30:44 by nmartins       #+#    #+#                */
/*   Updated: 2019/11/13 20:44:48 by nmartins      ########   odam.nl         */
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

void			*threadpool_worker(void *work_data)
{
	t_worker	*worker;

	worker = work_data;
	while (worker->work_status != IS_TERMINATING)
	{
		worker->work_status = IS_IDLE;
		while (worker->work_status == IS_IDLE || worker->curr_work == NULL)
		{
			if (worker->work_status == IS_TERMINATING)
				break ;
			usleep(1);
		}
		if (worker->work_status == IS_TERMINATING)
			break ;
		worker->curr_work->fn(worker->curr_work->argument);
		worker->curr_work = NULL;
	}
	pthread_exit(NULL);
	return (NULL);
}

void		debug_workers(t_worker_node *workers)
{
	t_worker_node	*node;

	node = workers;
	while (node)
	{
		ft_printf("[Worker %llu] Status: %s\n", node->worker.id, 
		node->worker.work_status == IS_IDLE 
		? "Idle" : (node->worker.work_status == IS_TERMINATING ? "Terminating" : "Working"));
		node = node->next;
	}
}

void		debug_work(t_work_node *work, t_worker_node *workers)
{
	size_t		i;
	size_t		j;
	size_t		w;
	t_work_node		*node;
	t_worker_node	*w_node;

	(void)debug_workers;
	node = work;
	i = 0;
	while (node)
	{
		i++;
		node = node->next;
	}
	j = 0;
	w = 0;
	w_node = workers;
	while (w_node)
	{
		if (w_node->worker.work_status == IS_WORKING)
			w++;
		j++;
		w_node = w_node->next;
	}
	ft_printf("-> Work in queue: %llu\n", i);
	ft_printf("-> Active workers [%llu/%llu]\n", w, j);
	ft_printf("-> Total work:     %llu\n", i + w);
}

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

	pool = (t_threadpool*)threadpool;
	while (pool->pool_status != IS_TERMINATING)
	{
		// debug_workers(pool->workers);
		if (pool->queue)
		{
			pthread_mutex_lock(&pool->lock);
			work_node = pool->queue;
			pool->queue = pool->queue->next;
			while (pool->pool_status != IS_TERMINATING)
			{
				usleep(1);
				if (assign_work(pool->workers, &work_node->work) == SUCCESS)
					break ;
			}
			pthread_mutex_unlock(&pool->lock);
		}
		usleep(1);
	}
	pthread_exit(NULL);
	return (NULL);
}

t_threadpool	*threadpool_init(size_t worker_count)
{
	t_threadpool	*pool;

	ft_printf("Creating Threadpool with %llu workers\n", worker_count);
	pool = (t_threadpool*)malloc(sizeof(t_threadpool));
	pool->worker_count = worker_count;
	pool->pool_status = IS_IDLE;
	pool->queue = NULL;
	allocate_workers(&pool->workers, worker_count);
	if (!pthread_mutex_lock(&pool->lock))
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
