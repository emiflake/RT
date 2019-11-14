/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   worker.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/13 15:30:36 by nmartins       #+#    #+#                */
/*   Updated: 2019/11/14 12:51:13 by nmartins      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#include "threadpool.h"

void			*threadpool_worker(void *work_data)
{
	t_worker	*worker;

	worker = work_data;
    while (worker->work_status != IS_TERMINATING)
    {
		usleep(1);
        if (worker->work_status == IS_WORKING && worker->curr_work != NULL)
        {
            worker->curr_work->fn(worker->curr_work->argument);
            worker->curr_work = NULL;
			if (worker->work_status == IS_TERMINATING)
				break ;
            worker->work_status = IS_IDLE;
        }
    }
	pthread_exit(NULL);
	return (NULL);
}