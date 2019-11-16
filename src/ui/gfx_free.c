/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   gfx_free.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/16 21:27:28 by nmartins       #+#    #+#                */
/*   Updated: 2019/11/16 21:29:36 by nmartins      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ui.h"

void	gfx_free(t_gfx_context	*ctx)
{
	TTF_CloseFont(ctx->font.font);
}
