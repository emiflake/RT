/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/20 15:26:18 by nmartins       #+#    #+#                */
/*   Updated: 2019/06/03 16:32:52 by nloomans      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

int		ft_printf(char *fmt, ...);

int		main(void)
{
	ft_printf("%d\n", ft_printf("Hello, World\n"));
	return (0);
}
