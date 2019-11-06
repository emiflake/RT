/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   writer_utils.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: nloomans <nloomans@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/07 13:46:12 by nloomans       #+#    #+#                */
/*   Updated: 2019/06/07 13:46:19 by nloomans      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

size_t	vector_cap_for_length(size_t length)
{
	size_t cap;

	cap = 64;
	while (cap < length)
		cap *= 2;
	return (cap);
}
