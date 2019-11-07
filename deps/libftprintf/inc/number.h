/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   number.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/27 14:50:39 by nmartins       #+#    #+#                */
/*   Updated: 2019/06/26 18:51:41 by nmartins      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef NUMBER_H
# define NUMBER_H

# include <stddef.h>

typedef struct	s_number
{
	char				sign;
	unsigned long long	value;
	unsigned char		base;
}				t_number;

#endif
