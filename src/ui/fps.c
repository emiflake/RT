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

#include "ui.h"

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

int		ui_get_fps(int do_tick)
{
	static int	frames;
	static int	preserved_frames;
	static long	last_time;
	long		curr_time;

	if (do_tick)
		frames++;
	curr_time = get_current_epoch();
	if (last_time + 1000 < curr_time)
	{
		preserved_frames = frames;
		frames = 0;
		last_time = curr_time;
	}
	return (preserved_frames);
}
