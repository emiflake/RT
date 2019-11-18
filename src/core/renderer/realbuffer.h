/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   realbuffer.h                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/17 15:28:24 by nmartins       #+#    #+#                */
/*   Updated: 2019/11/17 16:04:33 by nmartins      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef REALBUFFER_H
# define REALBUFFER_H

/*
** RealBuffer™ is a creative software solution (just kidding!)
**
** It's just a NxM pixel array but with t_vec instead of uint32_t, which results
** in a lot more precision for storing colours. This is useful for progressive
** rendering.
*/

# include <SDL2/SDL.h>

# include "algebra/vector/vector.h"

typedef struct	s_realbuffer
{
	size_t	width;
	size_t	height;

	t_vec	*buf;

	size_t	samples;
}				t_realbuffer;

t_realbuffer	*rb_create(size_t w, size_t h);
void			rb_free(t_realbuffer *buf);
void			rb_clear(t_realbuffer *buf);
void			rb_add_sample(
	t_realbuffer *buf, size_t x, size_t y, const t_vec *contrib);
void			rb_inc_sample(t_realbuffer *buf);

/*
** Write to SDL Buffer, compressing the samples
*/
void			rb_compress(const t_realbuffer *buf, SDL_Surface *surf);

#endif
