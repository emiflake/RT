/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   conversion.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: pacovali <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/12 18:56:23 by pacovali      #+#    #+#                 */
/*   Updated: 2019/01/23 17:53:36 by pacovali      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

REAL		deg_to_rad(REAL degrees)
{
	while (degrees > 360 || degrees < 0)
		degrees += (degrees < 0) ? 360 : -360;
	return (degrees * M_PI / 180);
}

REAL		rad_to_deg(REAL radians)
{
	while (radians > M_2_PI || radians < 0)
		radians += (radians < 0) ? M_2_PI : -M_2_PI;
	return (radians * 180 / M_PI);
}
