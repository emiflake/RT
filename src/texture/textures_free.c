/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   textures_free.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/21 17:31:29 by nmartins       #+#    #+#                */
/*   Updated: 2019/11/21 17:42:10 by nmartins      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "texture.h"

static void		clean_f(void *vptr)
{
	t_bucket_node	*node;
	t_texture		*tex;

	node = vptr;
	tex = node->value;
	free(node->key);
	texture_free(&tex);
}

void			textures_free(t_textures *tex)
{
	ash_hashmap_clean(tex->hashmap, clean_f);
	pthread_mutex_destroy(&tex->lock);
	free(tex);
}
