/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   renderer.h                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/07 16:32:18 by nmartins       #+#    #+#                */
/*   Updated: 2019/11/07 16:37:39 by nmartins      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDERER_H
# define RENDERER_H

# include <SDL2/SDL.h>

# include "core/scene/scene.h"

void	render_image(const t_scene *scene, SDL_Surface *surf);

#endif
