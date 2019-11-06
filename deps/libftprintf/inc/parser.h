/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parser.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/22 15:56:15 by nmartins       #+#    #+#                */
/*   Updated: 2019/06/26 18:58:09 by nmartins      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "token.h"

typedef struct	s_char2descriptor
{
	char			c;
	t_descriptor	descriptor;
}				t_char2descriptor;

typedef struct	s_str2size
{
	char	*str;
	t_size	size;
}				t_str2size;

int				parse_atoi(char **stream);
int				parse_atoi_wildcard(char **stream);
void			truncate_flags(t_token *dest);
int				parse_precision(t_flags *flags, char **stream);
int				parse_width(char **stream);
t_descriptor	parse_conversion_specifier(
					t_flags *flags,
					char **stream,
					int *has_errored);
t_size			parse_size(char **stream);
int				is_conversion_specification(const char *stream);
int				is_color_specification(const char *stream);

#endif
