/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   compdef.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/26 13:20:57 by nmartins       #+#    #+#                */
/*   Updated: 2019/11/14 19:26:08 by nmartins      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMPDEF_H
# define COMPDEF_H

/*
** This file is responsible for handling
** all compile-time variables that will
** affect the way the program works.
*/

/*
** By doing it this way, we are able to
** switch from floats to doubles.
*/
# define SUPERSAMPLE 1024

# define SUCCESS 0
# define FAILURE 1

# define BYTE char
# define REAL double

#endif
