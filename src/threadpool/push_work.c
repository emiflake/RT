/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_work.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/13 17:21:35 by nmartins       #+#    #+#                */
/*   Updated: 2019/11/14 15:43:30 by nmartins      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>
#include <stdlib.h>
#include <assert.h>

#include "threadpool.h"
#include "compdef.h"

int			threadpool_push_work(t_threadpool *pool, t_work *work)
{
	t_work_node	*work_node;

	work_node = (t_work_node*)malloc(sizeof(t_work_node));
	if (!work_node)
		return (FAILURE);
	assert(!pthread_mutex_lock(&pool->lock));
	work_node->next = pool->queue;
	work_node->work = work;
	pool->queue = work_node;
	assert(!pthread_mutex_unlock(&pool->lock));
	return (SUCCESS);
}
