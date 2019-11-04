/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   keystate.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/04 16:55:36 by nmartins       #+#    #+#                */
/*   Updated: 2019/11/04 17:00:36 by nmartins      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

#include "ui.h"

void				keystate_set_down(t_keystate *ks, t_key key)
{
	ks->keys[key] = true;
}

void				keystate_set_up(t_keystate *ks, t_key key)
{
	ks->keys[key] = false;
}

bool				keystate_is_down(const t_keystate *ks, t_key key)
{
	return (ks->keys[key]);
}

void				keystate_init(t_keystate *ks)
{
	size_t	i;

	i = 0;
	while (i < 512)
	{
		ks->keys[i] = false;
		i++;
	}
}

void				keystate_debug(const t_keystate *ks)
{
	size_t	i;

	i = 0;
	while (i < 512)
	{
		if (ks->keys[i])
		{
			ft_printf("%llu is down; ", i);
		}
		i++;
	}
	ft_printf("\n");
}
