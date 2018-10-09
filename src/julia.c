/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiriuk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/02 14:53:55 by abiriuk           #+#    #+#             */
/*   Updated: 2018/10/09 21:14:02 by abiriuk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <math.h>
#include "fractol.h"
#include "mlx.h"

int		fix(int button, int x, int y, void *param)
{
	t_all *all;

	all = (t_all*)param;
	if (x && y)
		;
	if (button == 1)
	{
		all->fix.c_re = all->mouse.c_re;
		all->fix.c_im = all->mouse.c_im;
		all->fix_num = 1;
	}
		return (0);
}

int     julia(t_num num, t_num mouse, int itter)
{
	double  z_re;
	double  z_im;
	int     i;
	double  z_re2;
	double  z_im2;

	i = 0;
	z_re = num.c_re;
	z_im = num.c_im;
	while (i < itter)
	{
		z_re2 = z_re * z_re;
		z_im2 = z_im * z_im;
		if (z_re2 + z_im2 > 4)
			break;
		z_im = 2 * z_re * z_im + mouse.c_im;
		z_re = z_re2 - z_im2 + mouse.c_re;
		i++;
	}
	return (i);
}

void	change_mot(t_pic *picture, t_all *all)
{
	int		i;
	t_num	num;
	int		res;
	
	all->zoom.min_re = -1.5;
	all->zoom.max_re = 1.5;
	all->zoom.min_im = -1.5;
	all->itter = 20;
	all->zoom.max_im = (all->zoom.min_im + (all->zoom.max_re -
				all->zoom.min_re) * VER / HOR);
	i = 0;
	mlx_hook(all->win_str.win_ptr, 6, 0, motion, all);
//	mlx_hook(all->win_str.win_ptr, 2, 5, move_jul, all);
//	mlx_mouse_hook(all->win_str.win_ptr, mouse_jul, all);
//	mlx_hook(all->win_str.win_ptr, 2, 5, precision, all);
	mlx_mouse_hook(all->win_str.win_ptr, fix, all);
	while(i < picture->img_mas)
	{
		num = transform_pix(i, all);
			if (all->fix_num == 1)
				res = julia(num, all->fix, all->itter);
			else
				res = julia(num, all->mouse, all->itter);
		picture->img_arr[i] = set_col(res, all->itter);
		i++;
	}
	mlx_put_image_to_window(all->win_str.mlx_ptr, all->win_str.win_ptr,
			picture->img_ptr, 0, 0);
}

int		motion(int x, int y, void *param)
{
	t_fact	fact;
	t_all	*all;

	all = (t_all *)param;
	fact.re_fact = ((all->zoom.max_re - all->zoom.min_re) / (HOR - 1));
	fact.im_fact = ((all->zoom.max_im - all->zoom.min_im) / (VER - 1));
	all->mouse.c_re = all->zoom.min_re + (x * fact.re_fact);
	all->mouse.c_im = all->zoom.max_im - (y * fact.im_fact);
	change_mot(all->picture, all);
	return (0);
}


