/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   writer.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/20 14:59:48 by nmartins       #+#    #+#                */
/*   Updated: 2019/06/07 13:52:07 by nloomans      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRITER_H
# define WRITER_H
# include <stddef.h>
# include <stdio.h>
# include <sys/types.h>

typedef struct	s_writer
{
	void	(*write)(struct s_writer *self, char *str, size_t length);
	void	*state;
	size_t	written;
	int		failed;
}				t_writer;

void			writer_write(t_writer *writer, char *str, size_t length);

/*
** Write to an fd
*/
typedef int		t_writer_fd_state;
void			writer_fd_write(t_writer *self, char *str, size_t length);

/*
** Write to a FILE
*/
typedef FILE	t_writer_file_state;
void			writer_file_write(t_writer *self, char *str, size_t length);

/*
** Write to auto-allocated string
*/
typedef struct	s_writer_alloc_state
{
	char	**str_ptr;
	size_t	len;
	size_t	cap;
}				t_writer_alloc_state;
void			writer_alloc_write(t_writer *self, char *str, size_t length);

typedef struct	s_writer_string_state
{
	char	*str_ptr;
	ssize_t	maximum;
	size_t	actually_written;
}				t_writer_string_state;
void			writer_string_write(t_writer *self, char *str, size_t length);

size_t			vector_cap_for_length(size_t length);

ssize_t			ft_vwprintf(t_writer *writer, char *fmt, va_list vlist);

#endif
