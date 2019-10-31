/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   json.h                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/31 14:03:38 by nmartins       #+#    #+#                */
/*   Updated: 2019/10/31 15:05:11 by nmartins      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef JSON_H
# define JSON_H

# include <stddef.h>
# include "compdef.h"

typedef char*	t_json_string;
typedef REAL	t_json_number;
typedef struct	s_kvp
{
	t_json_string		key;
	struct s_json_value	*value;
}				t_kvp;

typedef struct	s_json_dict
{
	// TODO: use ash-map
}				t_json_dict;

typedef struct	s_json_list_node
{
	struct s_json_value		*value;
	struct s_json_list_node	*next;
}				t_json_list_node;

typedef struct	s_json_list
{
	t_json_list_node	*root;
}				t_json_list;

/*
** Value := String
**		  | Number
**		  | Dictionary String -> Value
**		  | List Value
*/

typedef struct	s_json_value
{
	union {
		t_json_string	as_string;
		t_json_number	as_number;
		t_json_dict		as_dict;
		t_json_list		as_list;
	}	value;

	enum {
		JSON_STRING,
		JSON_NUMBER,
		JSON_DICT,
		JSON_LIST,
	}	type;
}				t_json_value;

t_json_value	*do_parse_string(const char **str);
t_json_value	*do_parse_number(const char **str);
t_json_value	*do_parse_dict(const char **str);
t_json_value	*do_parse_list(const char **str);
t_json_value	*do_parse_json(const char **str);
t_json_value	*parse_json(const char *str);

void			json_debug(const t_json_value *val);




#endif 
