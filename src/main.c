/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiriuk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/12 18:11:26 by abiriuk           #+#    #+#             */
/*   Updated: 2018/09/26 19:39:30 by abiriuk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <unistd.h>
#include "libft.h"
#include <stdlib.h>
#include <stdio.h>

void	error_msg(char *str)
{
	write(2, "ERROR: ", 7);
	write(2, "\x1b[31m", 6);
	write(2, str, ft_strlen(str));
	write(2, "\n", 1);
	exit(0);
}

void	check_name(char *name, t_all *all, t_pic *pic)
{
	if (ft_strequ(name, "Mandelbrot"))
	{

		wind(all, pic);
		change_px(pic, all);
	}
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
	t_all all;
	t_pic pic;

	all.picture = &pic;
	all.move.x = 0;
	all.move.y = 0;
	if (ac != 2)
	usage();
	check_name(av[1], &all, all.picture);
	mlx_loop(all.win_str.mlx_ptr);
}
