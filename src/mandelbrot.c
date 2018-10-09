/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiriuk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/18 16:57:22 by abiriuk           #+#    #+#             */
/*   Updated: 2018/10/09 20:26:13 by abiriuk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <math.h>
#include "fractol.h"

int		mandelbrot(t_num num, int itter)
{
	double	z_re;
	double	z_im;
	int 	i;
	double	z_re2;
	double	z_im2;

	i = 0;
	z_re = num.c_re;
	z_im = num.c_im;
	while (i < itter)
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

void    change_px(t_pic *picture, t_all *all)
{
	int     i;
	t_num   num;
	int     res;

	i = 0;
	mlx_hook(all->win_str.win_ptr, 2, 5, move, all);
	mlx_mouse_hook(all->win_str.win_ptr, mouse, all);
	mlx_hook(all->win_str.win_ptr, 2, 5, precision, all);
	while(i < picture->img_mas)
	{
		num = transform_pix(i, all);
		res = mandelbrot(num, all->itter);
		picture->img_arr[i] = set_col(res, all->itter);
		i++;
	}
	mlx_put_image_to_window(all->win_str.mlx_ptr, all->win_str.win_ptr,
			picture->img_ptr, 0, 0);
}

void    cover_px(t_all *all, t_pic *pic)
{
	all->zoom.min_re = -2.0;
	all->zoom.max_re = 1.0;
	all->zoom.min_im = -1.2;
	all->itter = 20;
	all->zoom.max_im = (all->zoom.min_im + (all->zoom.max_re -
				all->zoom.min_re) * VER / HOR);
	change_px(pic, all);
}
