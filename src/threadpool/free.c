/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   free.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/13 19:47:38 by nmartins       #+#    #+#                */
/*   Updated: 2019/11/13 20:54:34 by nmartins      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>
#include <stdlib.h>
#include "threadpool.h"

static void		warn_workers(t_worker_node *node)
{
	if (!node)
		return ;
	node->worker.work_status = IS_TERMINATING;
	warn_workers(node->next);
}

static void		wait_workers(t_worker_node *node)
{
	if (!node)
		return ;
	pthread_join(node->worker.thread, NULL);
	wait_workers(node->next);
}

static void		free_workers(t_worker_node *node)
{
	if (!node)
		return ;
	free_workers(node->next);
	free(node);
}

static void		free_queue(t_work_node *node)
{
	if (!node)
		return ;
	free_queue(node->next);
	ft_printf("Freeing Work (%p)\n", node->work);
	free(node);
}

void			threadpool_free(t_threadpool *pool)
{
	pool->pool_status = IS_TERMINATING;
	warn_workers(pool->workers);
	wait_workers(pool->workers);
	free_workers(pool->workers);
	pool->workers = NULL;
	pthread_join(pool->manager, NULL);
	free_queue(pool->queue);
	pool->queue = NULL;
	free(pool);
}
