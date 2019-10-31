/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/26 16:32:43 by nmartins       #+#    #+#                */
/*   Updated: 2019/10/31 21:54:29 by nmartins      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>
#include <assert.h>

#include "./algebra/vector/vector.h"
#include "./json/json.h"

int	main(void)
{
	const char *example = "{\"key\": [{\"num\": 42}, {\"hello\": \"world\", \"otherkey\": 69}], \"owo\": [{}]}";

	t_json_value *val = parse_json(example);

	json_debug(val);
	return (0);
}
