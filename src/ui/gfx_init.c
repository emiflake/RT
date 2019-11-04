/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   gfx_init.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/04 17:20:48 by nmartins       #+#    #+#                */
/*   Updated: 2019/11/04 17:50:09 by nmartins      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

#include "ui.h"
#include "text.h"

int				gfx_init(t_gfx_context *ctx)
{
	if (TTF_Init())
	{
		ft_printf("Unable to initialize TTF: %s\n", TTF_GetError());
		exit(1);
	}
	ctx->font = font_load("SpaceMono-Regular.ttf", 17);
	return (SUCCESS);
}
