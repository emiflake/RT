/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   common.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/06 14:33:49 by nmartins       #+#    #+#                */
/*   Updated: 2019/11/06 14:35:41 by nmartins      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMON_H
# define COMMON_H

# include "../compdef.h"

# include <stddef.h>

void	rt_memset(BYTE *buf, BYTE pat, size_t len);
void	rt_memcpy(BYTE *dest, BYTE *res, size_t len);
void	rt_realloc(BYTE **buf, size_t cur_size, size_t new_size);

#endif
