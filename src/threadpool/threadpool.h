/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   threadpool.h                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/13 15:17:16 by nmartins       #+#    #+#                */
/*   Updated: 2019/11/13 20:21:07 by nmartins      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef THREADPOOL_H
# define THREADPOOL_H

# include <pthread.h>

typedef void(*t_work_fn)(void*);

typedef enum	e_work_status
{
	IS_IDLE,
	IS_WORKING,
	IS_TERMINATING,
}				t_work_status;

typedef struct	s_work
{
	t_work_fn	fn;
	void		*argument;
}				t_work;

typedef struct	s_worker
{
	t_work			*curr_work;
	pthread_t		thread;
	t_work_status	work_status;
	size_t			id;
}				t_worker;

typedef struct	s_worker_node
{
	t_worker				worker;
	struct s_worker_node	*next;
}				t_worker_node;

typedef struct	s_work_node
{
	t_work				work;
	struct s_work_node	*next;
}				t_work_node;

typedef struct	s_threadpool
{
	pthread_mutex_t	lock;
	t_work_node		*queue;
	t_worker_node	*workers;
	pthread_t		manager;
	size_t			worker_count;
	t_work_status	pool_status;
}				t_threadpool;

t_threadpool	*threadpool_init(size_t	worker_count);
void			threadpool_free(t_threadpool *pool);
int				threadpool_push_work(t_threadpool *pool, t_work work);

/*
** Threads
*/
void			*threadpool_worker(void *work_data);
void			*threadpool_manager(void *threadpool);
void			debug_workers(t_worker_node *workers);
void			debug_work(t_work_node *work, t_worker_node *workers);

#endif
