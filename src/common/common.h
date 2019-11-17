/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   common.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/06 14:33:49 by nmartins       #+#    #+#                */
/*   Updated: 2019/11/17 14:26:50 by nmartins      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMON_H
# define COMMON_H

# include "../compdef.h"

# include <stddef.h>
# include <stdbool.h>

void		rt_memset(BYTE *buf, BYTE pat, size_t len);
void		rt_memcpy(BYTE *dest, BYTE *res, size_t len);
void		rt_realloc(BYTE **buf, size_t cur_size, size_t new_size);
int			rt_strcmp(const char *a, const char *b);
bool		rt_isdigit(char c);
bool		rt_isspace(char c);
long double	rt_strtold10(const char *str, const char **endnum);

#endif
