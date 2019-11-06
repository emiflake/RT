/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/20 15:27:11 by nmartins       #+#    #+#                */
/*   Updated: 2019/06/07 13:52:26 by nloomans      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <sys/types.h>
# include <stdio.h>

ssize_t	ft_printf(char *fmt, ...);
ssize_t	ft_vprintf(char *fmt, va_list vlist);
ssize_t	ft_dprintf(int fd, char *fmt, ...);
ssize_t	ft_vdprintf(int fd, char *fmt, va_list vlist);
ssize_t	ft_fprintf(FILE *file, char *fmt, ...);
ssize_t ft_vfprintf(FILE *file, char *fmt, va_list vlist);
ssize_t	ft_asprintf(char **dest, char *fmt, ...);
ssize_t	ft_vasprintf(char **dest, char *fmt, va_list vlist);
ssize_t	ft_snprintf(char *dest, ssize_t capacity, char *fmt, ...);
ssize_t	ft_vsnprintf(char *dest, ssize_t capacity, char *fmt, va_list vlist);
ssize_t	ft_sprintf(char *dest, char *fmt, ...);
ssize_t	ft_vsprintf(char *dest, char *fmt, va_list vlist);

#endif
