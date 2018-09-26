/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiriuk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/12 18:11:26 by abiriuk           #+#    #+#             */
/*   Updated: 2018/09/20 17:27:48 by abiriuk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <unistd.h>

void	error_msg(char *str)
{
	write(2, "ERROR: ", 7);
	write(2, "\x1b[31m", 6);
	write(2, str, ft_strlen(str));
	write(2, "\n", 1);
	exit(0);
}

void	check_name(char *name)
{
	if (ft_strequ(name, "Mandelbrot"))
		;
	else if (ft_strequ(name, "Julia"))
		;
	else
		error_msg("Wrong name");
}

static void	usage(void)
{
	ft_putendl("usage: ./fractol (fractol name)\n\
			Mandelbrot\n\
			Julia\n\
			");
	exit(0);
}

int		main(int ac, char **av)
{
	if (ac != 2)
	usage();
	check_name(av[1]);
}
