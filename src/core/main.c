/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/26 16:32:43 by nmartins       #+#    #+#                */
/*   Updated: 2019/11/01 19:36:59 by nmartins      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>
#include <assert.h>

#include "./algebra/vector/vector.h"
#include "./json/json.h"

int	main(void)
{
	const char *example = " { \"key\": [ {\"num\": 42}, {\"hello\": \"world\", \"otherkey\": 69} ], \"owo\": [ { }, { }, 1, 2, 3, 4, \"lol\" ] }";

	t_json_value *val = parse_json(example);

	json_debug(val);
	json_free(val);
	getchar();
	return (0);
}
