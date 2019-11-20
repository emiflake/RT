/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/17 14:45:58 by nmartins       #+#    #+#                */
/*   Updated: 2019/11/18 12:52:32 by nmartins      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

#include "settings.h"
#include "json/json.h"

int			settings_init(t_settings *settings)
{
	t_json_value	*json_root;

	json_root = read_json("settings.json");
	if (!json_root)
	{
		ft_printf("Settings file could not be loaded.\n");
		return (FAILURE);
	}
	settings->width = dict_def_double(json_root, "width", 1280);
	settings->height = dict_def_double(json_root, "height", 720);
	json_free(json_root);
	return (SUCCESS);
}
