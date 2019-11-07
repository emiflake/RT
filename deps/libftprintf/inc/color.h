/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   color.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/25 01:25:05 by nmartins       #+#    #+#                */
/*   Updated: 2019/06/26 18:51:13 by nmartins      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLOR_H
# define COLOR_H

typedef enum	e_color
{
	E_RESET,
	E_BLACK,
	E_GRAY,
	E_RED,
	E_GREEN,
	E_YELLOW,
	E_BLUE,
	E_MAGENTA,
	E_CYAN,
	E_WHITE,
	E_UNDERLINE,
	E_REVERSED
}				t_color;

# ifdef __APPLE__
#  define COLOR_RESET     "\x1b[0;0m"
#  define COLOR_BLACK     "\x1b[0;30m"
#  define COLOR_GRAY      "\x1b[0;37m"
#  define COLOR_RED       "\x1b[0;31m"
#  define COLOR_GREEN     "\x1b[0;32m"
#  define COLOR_YELLOW    "\x1b[0;33m"
#  define COLOR_BLUE      "\x1b[0;34m"
#  define COLOR_MAGENTA   "\x1b[0;35m"
#  define COLOR_CYAN      "\x1b[0;36m"
#  define COLOR_WHITE     "\x1b[0;37m"
#  define COLOR_UNDERLINE "\x1b[1;4m"
#  define COLOR_REVERSED  "\x1b[1;7m"
# else
#  define COLOR_RESET     "\033[0;0m"
#  define COLOR_BLACK     "\033[0;30m"
#  define COLOR_GRAY      "\033[0;37m"
#  define COLOR_RED       "\033[0;31m"
#  define COLOR_GREEN     "\033[0;32m"
#  define COLOR_YELLOW    "\033[0;33m"
#  define COLOR_BLUE      "\033[0;34m"
#  define COLOR_MAGENTA   "\033[0;35m"
#  define COLOR_CYAN      "\033[0;36m"
#  define COLOR_WHITE     "\033[1;37m"
#  define COLOR_UNDERLINE "\033[1;4m"
#  define COLOR_REVERSED  "\033[1;7m"
# endif

#endif
