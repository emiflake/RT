/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   keystate.h                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/28 14:54:01 by nmartins       #+#    #+#                */
/*   Updated: 2019/10/28 15:03:45 by nmartins      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef KEYSTATE_H
# define KEYSTATE_H

# include <compdef.h>
# include <stdint.h>

typedef uint32_t 	t_key;

typedef struct		s_keystate
{
	bool	keys[512];
}					t_keystate;

void				keystate_set_down(t_keystate *ks, t_key key);
void				keystate_set_up(t_keystate *ks, t_key key);
bool				keystate_is_down(t_keystate *ks, t_key key);

#endif