/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   wait.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/13 23:06:01 by nmartins       #+#    #+#                */
/*   Updated: 2019/11/14 12:49:13 by nmartins      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "threadpool.h"

/*
** Wait for the threadpool to be done with all of the current work
** (Blocking)
*/

void	threadpool_wait(t_threadpool *pool)
{
	while (pool->queue)
		usleep(100);
}