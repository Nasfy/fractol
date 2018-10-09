/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_zoom.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiriuk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/30 17:22:17 by abiriuk           #+#    #+#             */
/*   Updated: 2018/10/09 17:25:44 by abiriuk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	interpolate(double start, double end, double inter)
{
	return (start + ((end - start) * inter));
}	

int		mouse(int button, int x, int y, void *param)
{
	t_all	*all;
	t_fact	mouse;
	double	zm_fctr = 0.0;
	t_fact	rel;

	all = (t_all *)param;
	if (button == 5) 
		zm_fctr = 1 / 1.05;
	else if (button == 4)
		zm_fctr = 1 / 0.95;
	rel.re_fact = (all->zoom.max_re - all->zoom.min_re) / (HOR - 1);
	rel.im_fact = (all->zoom.max_im - all->zoom.min_im) / (VER - 1);
	mouse.re_fact = all->zoom.min_re + ((double)x * rel.re_fact);
	mouse.im_fact = all->zoom.max_im - ((double)y * rel.im_fact);
	all->zoom.min_re = interpolate(mouse.re_fact, all->zoom.min_re, zm_fctr);
	all->zoom.min_im = interpolate(mouse.im_fact, all->zoom.min_im, zm_fctr);
	all->zoom.max_re = interpolate(mouse.re_fact, all->zoom.max_re, zm_fctr);
	all->zoom.max_im = interpolate(mouse.im_fact, all->zoom.max_im, zm_fctr);
	change_px(all->picture, all);
	return (0);
}

int		mouse_clt(int button, int x, int y, void *param)
{
	t_all	*all;
	t_fact	mouse;
	double	zm_fctr = 0.0;
	t_fact	rel;

	all = (t_all *)param;
	if (button == 5) 
		zm_fctr = 1 / 1.05;
	else if (button == 4)
		zm_fctr = 1 / 0.95;
	rel.re_fact = (all->zoom.max_re - all->zoom.min_re) / (HOR - 1);
	rel.im_fact = (all->zoom.max_im - all->zoom.min_im) / (VER - 1);
	mouse.re_fact = all->zoom.min_re + ((double)x * rel.re_fact);
	mouse.im_fact = all->zoom.max_im - ((double)y * rel.im_fact);
	all->zoom.min_re = interpolate(mouse.re_fact, all->zoom.min_re, zm_fctr);
	all->zoom.min_im = interpolate(mouse.im_fact, all->zoom.min_im, zm_fctr);
	all->zoom.max_re = interpolate(mouse.re_fact, all->zoom.max_re, zm_fctr);
	all->zoom.max_im = interpolate(mouse.im_fact, all->zoom.max_im, zm_fctr);
	change_clt(all->picture, all);
	return (0);
}

int		mouse_hrt(int button, int x, int y, void *param)
{
	t_all	*all;
	t_fact	mouse;
	double	zm_fctr = 0.0;
	t_fact	rel;

	all = (t_all *)param;
	if (button == 5) 
		zm_fctr = 1 / 1.05;
	else if (button == 4)
		zm_fctr = 1 / 0.95;
	rel.re_fact = (all->zoom.max_re - all->zoom.min_re) / (HOR - 1);
	rel.im_fact = (all->zoom.max_im - all->zoom.min_im) / (VER - 1);
	mouse.re_fact = all->zoom.min_re + ((double)x * rel.re_fact);
	mouse.im_fact = all->zoom.max_im - ((double)y * rel.im_fact);
	all->zoom.min_re = interpolate(mouse.re_fact, all->zoom.min_re, zm_fctr);
	all->zoom.min_im = interpolate(mouse.im_fact, all->zoom.min_im, zm_fctr);
	all->zoom.max_re = interpolate(mouse.re_fact, all->zoom.max_re, zm_fctr);
	all->zoom.max_im = interpolate(mouse.im_fact, all->zoom.max_im, zm_fctr);
	change_hrt(all->picture, all);
	return (0);
}
