/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fps.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/04 17:52:19 by nmartins       #+#    #+#                */
/*   Updated: 2019/11/04 17:56:46 by nmartins      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "renderer.h"

#include <time.h>

long	get_current_epoch(void)
{
	long			ns;
	time_t			s;
	struct timespec	spec;

	clock_gettime(CLOCK_REALTIME, &spec);
	s = spec.tv_sec;
	ns = spec.tv_nsec;
	return (s * 1000 + ns / 1000000);
}

REAL	ui_get_fps(int do_tick)
{
	static REAL	seconds_elapsed;
	static long	last_time = 0;
	long		curr_time;

	if (last_time == 0)
		last_time = get_current_epoch();
	if (do_tick)
	{
		curr_time = get_current_epoch();
		seconds_elapsed = (curr_time - last_time) / 1000.0;
		last_time = curr_time;
	}
	return (seconds_elapsed + 0.0001);
}
