/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   json.h                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/31 14:03:38 by nmartins       #+#    #+#                */
/*   Updated: 2019/11/20 21:50:35 by nmartins      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef JSON_H
# define JSON_H

# include <stddef.h>
# include <stdbool.h>
# include "algebra/vector/vector.h"
# include "compdef.h"
# include "hashmap/ashmap.h"

typedef char*				t_json_string;
typedef REAL				t_json_number;
typedef struct				s_kvp
{
	t_json_string			key;
	struct s_json_value		*value;
}							t_kvp;

typedef struct				s_json_dict
{
	t_hashmap				*hashmap;
}							t_json_dict;

typedef struct				s_json_list_node
{
	struct s_json_value		*value;
	struct s_json_list_node	*next;
}							t_json_list_node;

typedef struct				s_json_list
{
	t_json_list_node		*root;
}							t_json_list;

/*
** Value := String
**		  | Number
**		  | Dictionary String -> Value
**		  | List Value
*/

typedef struct				s_json_value
{
	union {
		t_json_string		as_string;
		t_json_number		as_number;
		t_json_dict			as_dict;
		t_json_list			as_list;
	}						value;

	enum {
		JSON_STRING,
		JSON_NUMBER,
		JSON_DICT,
		JSON_LIST,
	}	type;
}							t_json_value;

/*
** Parsing functions
*/

t_json_value				*do_parse_string(const char **str);
t_json_value				*do_parse_number(const char **str);
t_json_value				*do_parse_dict(const char **str);
t_json_value				*do_parse_list(const char **str);
t_json_value				*do_parse_json(const char **str);
t_json_value				*parse_json(const char *str);

t_json_value				*read_json(const char *filename);

typedef struct				s_str_vec
{
	char					*str;
	size_t					len;
	size_t					cap;
}							t_str_vec;

bool						read_file(const char *filename, char **res);

/*
** Util functions
*/

void						skip_whitespace(const char **str);

/*
** Misc functions
*/

void						do_json_debug(
								const t_json_value *val, size_t indentation);

void						json_debug(const t_json_value *val);

void						json_free(t_json_value *val);

void						do_dict_debug(
								const t_json_dict *dict, size_t indentation);

/*
** Combinators
*/

t_json_value				*dict_get(
			const t_json_value *val, char *key);

double						dict_def_double(
			const t_json_value *val, char *key, double def);

char						*dict_def_string(
			const t_json_value *val, char *key, char *str);

void						dict_def_vec(
			const t_json_value *val, char *key, const t_vec def, t_vec *out);

#endif
