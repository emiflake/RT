/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   std.h                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: nloomans <nloomans@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/07/08 15:50:14 by nloomans       #+#    #+#                */
/*   Updated: 2019/07/08 17:05:33 by nloomans      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef STD_H
# define STD_H

# include <stddef.h>

size_t		std_strlen(const char *s);
void		std_strrev(char *str);
int			std_strncmp(const char *s1, const char *s2, size_t n);
char		*std_strchr(const char *haystack, int needle);
void		*std_memset(void *source, int constant, size_t size);
void		*std_memcpy(void *dest, const void *src, size_t n);
int			std_memcmp(const void *s1, const void *s2, size_t n);
void		*std_realloc(void *mem, size_t s_len, size_t n_len);
int			std_isprint(int c);
int			std_isdigit(int c);
int			std_tolower(int c);
int			std_max(int a, int b);
int			std_min(int a, int b);

#endif
