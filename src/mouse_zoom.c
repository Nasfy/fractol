/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_zoom.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiriuk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/30 17:22:17 by abiriuk           #+#    #+#             */
/*   Updated: 2018/10/10 19:29:55 by abiriuk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	interpolate(double start, double end, double inter)
{
	return (start + ((end - start) * inter));
}	

int		mouse(int button, int x, int y, void *param)
{
	t_all *const	all = (t_all *)param;
	t_fact			mouse;
	double			zm_fctr;

	if (button != 5 && button != 4)
		return (0);
	zm_fctr = 1 / 1.05;
	if (button == 5)
		all->itter += 1;
	else if (button == 4)
	{
		zm_fctr = 1 / 0.95;
		if (all->itter >= 5)
			all->itter -= 1;
	}
	all->re_fact = (all->zoom.max_re - all->zoom.min_re) / (HOR - 1);
	all->im_fact = (all->zoom.max_im - all->zoom.min_im) / (VER - 1);
	mouse.re_fact = all->zoom.min_re + ((double)x * all->re_fact);
	mouse.im_fact = all->zoom.max_im - ((double)y * all->im_fact);
	all->zoom.min_re = interpolate(mouse.re_fact, all->zoom.min_re, zm_fctr);
	all->zoom.min_im = interpolate(mouse.im_fact, all->zoom.min_im, zm_fctr);
	all->zoom.max_re = interpolate(mouse.re_fact, all->zoom.max_re, zm_fctr);
	all->zoom.max_im = interpolate(mouse.im_fact, all->zoom.max_im, zm_fctr);
	change_px(all->picture, all);
	return (0);
}

int		mouse_jul(int button, int x, int y, void *param)
{
	t_all	*const	all = (t_all *)param;
	t_fact	mouse;
	double	zm_fctr = 0.0;

	if (button != 5 && button != 4)
		return (0);
	zm_fctr = 1 / 1.05;
	if (button == 5)
		all->itter += 1;
	else if (button == 4)
	{
		zm_fctr = 1 / 0.95;
		if (all->itter >= 5)
			all->itter -= 1;
	}

	all->re_fact = (all->zoom.max_re - all->zoom.min_re) / (HOR - 1);
	all->im_fact = (all->zoom.max_im - all->zoom.min_im) / (VER - 1);
	mouse.re_fact = all->zoom.min_re + ((double)x * all->re_fact);
	mouse.im_fact = all->zoom.max_im - ((double)y * all->im_fact);
	all->zoom.min_re = interpolate(mouse.re_fact, all->zoom.min_re, zm_fctr);
	all->zoom.min_im = interpolate(mouse.im_fact, all->zoom.min_im, zm_fctr);
	all->zoom.max_re = interpolate(mouse.re_fact, all->zoom.max_re, zm_fctr);
	all->zoom.max_im = interpolate(mouse.im_fact, all->zoom.max_im, zm_fctr);
	change_mot(all->picture, all);
	return (0);
}

int		mouse_clt(int button, int x, int y, void *param)
{
	t_all	*const	all = (t_all *)param;
	t_fact	mouse;
	double	zm_fctr = 0.0;

	if (button != 5 && button != 4)
		return (0);
	zm_fctr = 1 / 1.05;
	if (button == 5)
		all->itter += 1;
	else if (button == 4)
	{
		zm_fctr = 1 / 0.95;
		if (all->itter >= 5)
			all->itter -= 1;
	}
	all->re_fact = (all->zoom.max_re - all->zoom.min_re) / (HOR - 1);
	all->im_fact = (all->zoom.max_im - all->zoom.min_im) / (VER - 1);
	mouse.re_fact = all->zoom.min_re + ((double)x * all->re_fact);
	mouse.im_fact = all->zoom.max_im - ((double)y * all->im_fact);
	all->zoom.min_re = interpolate(mouse.re_fact, all->zoom.min_re, zm_fctr);
	all->zoom.min_im = interpolate(mouse.im_fact, all->zoom.min_im, zm_fctr);
	all->zoom.max_re = interpolate(mouse.re_fact, all->zoom.max_re, zm_fctr);
	all->zoom.max_im = interpolate(mouse.im_fact, all->zoom.max_im, zm_fctr);
	change_clt(all->picture, all);
	return (0);
}

int		mouse_hrt(int button, int x, int y, void *param)
{
	t_all	*const	all = (t_all *)param;
	t_fact	mouse;
	double	zm_fctr = 0.0;

	if (button != 5 && button != 4)
		return (0);
	zm_fctr = 1 / 1.05;
	if (button == 5)
		all->itter += 1;
	else if (button == 4)
	{
		zm_fctr = 1 / 0.95;
		if (all->itter >= 5)
			all->itter -= 1;
	}
	all->re_fact = (all->zoom.max_re - all->zoom.min_re) / (HOR - 1);
	all->im_fact = (all->zoom.max_im - all->zoom.min_im) / (VER - 1);
	mouse.re_fact = all->zoom.min_re + ((double)x * all->re_fact);
	mouse.im_fact = all->zoom.max_im - ((double)y * all->im_fact);
	all->zoom.min_re = interpolate(mouse.re_fact, all->zoom.min_re, zm_fctr);
	all->zoom.min_im = interpolate(mouse.im_fact, all->zoom.min_im, zm_fctr);
	all->zoom.max_re = interpolate(mouse.re_fact, all->zoom.max_re, zm_fctr);
	all->zoom.max_im = interpolate(mouse.im_fact, all->zoom.max_im, zm_fctr);
	change_hrt(all->picture, all);
	return (0);
}
