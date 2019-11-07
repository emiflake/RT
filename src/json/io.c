/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   io.c                                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/06 14:23:22 by nmartins       #+#    #+#                */
/*   Updated: 2019/11/06 15:26:16 by nmartins      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <ft_printf.h>

#include "json.h"
#include "../common/common.h"

#define BLOCK_SIZE 256
#define STARTING_VEC_SIZE	1024

static void	vector_grow(t_str_vec *vec, size_t new_min_size)
{
	size_t	actual_size;

	actual_size = STARTING_VEC_SIZE;
	while (actual_size < new_min_size)
		actual_size *= 2;
	rt_realloc(&vec->str, vec->cap, actual_size);
	vec->cap = actual_size;
}

static void	vector_extend(t_str_vec *vec, char str[BLOCK_SIZE], ssize_t strlen)
{
	if (vec->len + strlen > vec->cap)
		vector_grow(vec, vec->len + strlen);
	rt_memcpy(&vec->str[vec->len], str, strlen);
	vec->len = vec->len + strlen;
}

static bool	read_fd(const int fd, char **res)
{
	t_str_vec	vec;
	char		buf[BLOCK_SIZE];
	ssize_t		bytes_read;

	vec.str = (char*)malloc(STARTING_VEC_SIZE);
	vec.len = 0;
	vec.cap = STARTING_VEC_SIZE;
	bytes_read = 1;
	while (bytes_read > 0)
	{
		rt_memset(buf, 0, BLOCK_SIZE);
		bytes_read = read(fd, buf, BLOCK_SIZE - 1);
		if (bytes_read < 0)
		{
			free(vec.str);
			*res = NULL;
			return (FAILURE);
		}
		vector_extend(&vec, buf, bytes_read);
	}
	vector_extend(&vec, "\0", 1);
	*res = vec.str;
	return (SUCCESS);
}

bool		read_file(const char *filename, char **res)
{
	char	dummy_buf[1];
	int		fd;

	fd = open(filename, O_RDONLY);
	if (!fd)
		return (FAILURE);
	if (read(fd, dummy_buf, 0) < 0)
	{
		close(fd);
		return (FAILURE);
	}
	if (read_fd(fd, res) != SUCCESS)
	{
		close(fd);
		return (FAILURE);
	}
	close(fd);
	return (SUCCESS);
}
