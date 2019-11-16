/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   debug.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/15 22:59:27 by nmartins       #+#    #+#                */
/*   Updated: 2019/11/15 23:01:25 by nmartins      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

#include "bbox.h"

void	bbox_debug(const t_bbox *bbox)
{
	ft_printf("min: %lf %lf %lf\n", bbox->min.x, bbox->min.y, bbox->min.z);
	ft_printf("max: %lf %lf %lf\n", bbox->max.x, bbox->max.y, bbox->max.z);
}
