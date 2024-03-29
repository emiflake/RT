/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   settings.h                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/17 14:44:12 by nmartins       #+#    #+#                */
/*   Updated: 2019/11/20 17:02:14 by nmartins      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef SETTINGS_H
# define SETTINGS_H

# include <stddef.h>

typedef struct	s_settings
{
	size_t		width;
	size_t		height;
}				t_settings;

int				settings_init(t_settings *settings);

#endif
