/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_work.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/13 17:21:35 by nmartins       #+#    #+#                */
/*   Updated: 2019/11/13 19:20:07 by nmartins      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>
#include <stdlib.h>

#include "threadpool.h"
#include "compdef.h"

int			threadpool_push_work(t_threadpool *pool, t_work work)
{
	t_work_node	*work_node;

	pthread_mutex_lock(&pool->lock);
	work_node = (t_work_node*)malloc(sizeof(t_work_node));
	if (!work_node)
	{
		pthread_mutex_unlock(&pool->lock);
		return (FAILURE);
	}
	work_node->next = pool->queue;
	work_node->work = work;
	pool->queue = work_node;
	pthread_mutex_unlock(&pool->lock);
	return (SUCCESS);
}
