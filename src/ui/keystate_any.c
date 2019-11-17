/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   keystate_any.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/17 18:30:15 by nmartins       #+#    #+#                */
/*   Updated: 2019/11/17 18:34:30 by nmartins      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

#include "keystate.h"

bool	keystate_any(t_keystate *ks)
{
	size_t i;

	i = 0;
	while (i < sizeof(ks->keys) / sizeof(ks->keys[0]))
	{
		if (ks->keys[i])
			return (true);
		i++;
	}
	return (false);
}
