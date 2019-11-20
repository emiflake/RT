/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   texture.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: jandre-d <jandre-d@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/15 12:03:10 by jandre-d       #+#    #+#                */
/*   Updated: 2019/11/20 17:24:24 by jandre-d      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEXTURE_H
# define TEXTURE_H

# include "../../deps/libimg/includes/libimg.h"
# include "../hashmap/ashmap.h"
# include "../common/common.h"
# include "../algebra/vector/vector.h"
# include "../../deps/libftprintf/ft_printf.h"
# include "../perlin_noise/perlin_noise.h"

typedef struct	s_texture
{
	t_img		*img;
}				t_texture;

typedef struct	s_textures
{
	t_hashmap	*hashmap;
}				t_textures;

t_texture		*get_texture(t_textures *textures, char *key);
t_texture		*load_texture_file(t_textures *textures, char *name);
t_textures		*texture_init();
t_vec			uv_texel(t_textures *textures, char *key, REAL u, REAL v);
void			texture_free(t_texture **texture);
t_texture		*texture_new();

bool			generate_textures(t_textures *textures);
bool			generate_texture_lines(t_texture *texture);
bool			generate_texture_wood(t_texture *texture);
bool			generate_texture_noise(t_texture *texture);

#endif
