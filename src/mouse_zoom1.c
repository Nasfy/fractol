/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_zoom1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiriuk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/10 17:10:22 by abiriuk           #+#    #+#             */
/*   Updated: 2018/10/10 19:21:25 by abiriuk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		mouse_buf(int button, int x, int y, void *param)
{
    t_all	*const	all = (t_all *)param;
    t_fact			mouse;
    double			zm_fctr = 0.0;

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
	change_buf(all->picture, all);
	return (0);
}

int		mouse_tri(int button, int x, int y, void *param)
{
	t_all   *const	all = (t_all *)param;
	t_fact			mouse;
	double			zm_fctr = 0.0;

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
	change_tri(all->picture, all);
	return (0);
}
