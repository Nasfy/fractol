/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiriuk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/18 16:57:22 by abiriuk           #+#    #+#             */
/*   Updated: 2018/09/26 19:22:43 by abiriuk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <math.h>
#include "fractol.h"

int		mandelbrot(t_num num)
{
	double	z_re;
	double	z_im;
	int 	i;
	double	z_re2;
	double	z_im2;

	i = 0;
	z_re = num.c_re;
	z_im = num.c_im;
	while (i < ITTER)
	{
		z_re2 = z_re * z_re;
		z_im2 = z_im * z_im;
		if (z_re2 + z_im2 > 4)
			break;
		z_im = 2 * z_re * z_im + num.c_im;
		z_re = z_re2 - z_im2 + num.c_re;
		i++;
	}
	return (i);
}
