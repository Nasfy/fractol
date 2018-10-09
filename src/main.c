/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiriuk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/12 18:11:26 by abiriuk           #+#    #+#             */
/*   Updated: 2018/10/09 17:31:50 by abiriuk          ###   ########.fr       */
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
	wind(all, pic);
	if (ft_strequ(name, "Mandelbrot"))
		cover_px(all, pic);
	else if (ft_strequ(name, "Julia")) // сделать чтоб двигалась норм//
		change_mot(pic, all);
	else if (ft_strequ(name, "Celtic"))
		cover_clt(all, pic);
	else if (ft_strequ(name, "Heart"))
		cover_hrt(all, pic);
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
