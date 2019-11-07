/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   writer.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/20 15:04:21 by nmartins       #+#    #+#                */
/*   Updated: 2019/08/22 13:47:02 by nloomans      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include "std.h"
#include "writer.h"

void	writer_write(t_writer *writer, char *str, size_t length)
{
	writer->write(writer, str, length);
}

void	writer_fd_write(t_writer *self, char *str, size_t length)
{
	self->written += length;
	if (write(*(t_writer_fd_state *)self->state, str, length) == -1)
		self->failed = 1;
}

void	writer_file_write(t_writer *self, char *str, size_t length)
{
	self->written += length;
	fwrite(str, length, 1, (t_writer_file_state *)self->state);
}

/*
** we append using a vector-ish method by doubling the size of the string if it
** doesn't fit anymore
**
** cap: the total capisity of the array. This would be the value you get by
**      running sizeof(str) if str was an array on the stack.
** len: the amount of bytes actually used for the string, excluding the
**      NULL-terminator.
**
** len + 1 must always be less-or-equal-to cap. The +1 ensures that a
** NULL-terminator is always present.
*/

void	writer_alloc_write(t_writer *self, char *str, size_t length)
{
	t_writer_alloc_state	*state;
	size_t					new_cap;

	state = (t_writer_alloc_state*)self->state;
	if (self->failed)
		return ;
	if (state->len + length + 1 > state->cap)
	{
		new_cap = vector_cap_for_length(state->len + length + 1);
		*state->str_ptr = std_realloc(*state->str_ptr, state->cap, new_cap);
		state->cap = new_cap;
		if (*state->str_ptr == NULL)
		{
			self->failed = 1;
			return ;
		}
	}
	if (std_memcpy(*state->str_ptr + state->len, str, length) == NULL)
	{
		self->failed = 1;
		return ;
	}
	state->len += length;
	(*state->str_ptr)[state->len] = '\0';
	self->written += length;
}

void	writer_string_write(t_writer *self, char *str, size_t length)
{
	t_writer_string_state	*state;
	size_t					to_write;

	state = (t_writer_string_state*)self->state;
	self->written += length;
	if ((state->actually_written + length > (size_t)state->maximum)
		&& state->maximum >= 0)
	{
		to_write = state->maximum - state->actually_written;
		std_memcpy(state->str_ptr + state->actually_written, str, to_write);
		state->actually_written += to_write;
	}
	else
	{
		std_memcpy(state->str_ptr + state->actually_written, str, length);
		state->actually_written += length;
	}
}
