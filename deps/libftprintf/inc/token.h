/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   token.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/22 14:02:33 by nmartins       #+#    #+#                */
/*   Updated: 2019/06/26 18:53:44 by nmartins      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKEN_H
# define TOKEN_H

# include "writer.h"
# include <stdarg.h>
# include <sys/types.h>

typedef enum	e_descriptor
{
	E_TXT,
	E_PERCENT,
	E_INT,
	E_STR,
	E_UNS,
	E_PTR,
	E_HEX,
	E_CHR,
	E_OCT,
	E_FLOAT,
	E_MEMORY,
	E_COLOR,
}				t_descriptor;

typedef	short	t_flags;

# define FLAGS_ZEROPAD		(1 << 0)
# define FLAGS_LEFTALIGN	(1 << 1)
# define FLAGS_PLUS			(1 << 2)
# define FLAGS_SPACE		(1 << 3)
# define FLAGS_HASH			(1 << 4)
# define FLAGS_PRECISION	(1 << 5)
# define FLAGS_CAPITAL		(1 << 6)

# define DEFERRED_WILDCARD (-1)

typedef enum	e_size
{
	E_HH,
	E_H,
	E_N,
	E_L,
	E_LL,
}				t_size;

typedef struct	s_token
{
	t_descriptor			type;
	t_flags					flags;
	int						width;
	t_size					size;
	int						precision;
	char					*s_value;
	size_t					s_length;
}				t_token;

int				parse_token(t_token *dest, char **stream);
void			run_token(t_writer *writer, va_list vlist, t_token *token);
void			debug_token(t_token *token);

#endif
