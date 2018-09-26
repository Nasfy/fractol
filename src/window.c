/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiriuk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/12 16:35:33 by abiriuk           #+#    #+#             */
/*   Updated: 2018/09/20 20:25:57 by abiriuk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

void	wind(t_all *all, t_pic *pic)
{
	all->win_str.mlx_ptr = mlx_init();
	all->win_str.win_ptr = mlx_new_window(all->win_str.mlx_ptr, 
			HOR, VER, "fractol");
	mlx_hook(all->win_str.win_ptr, 17, 1L << 17, exit_x, (void *)0);
	mlx_key_hook(all->win_str.win_ptr, exit_esc, (void *)0);
	make_img(pic, all);
}

int		make_img(t_pic *picture, t_all *all)
{
	picture->pix_mas = 8;
	picture->line_mas = picture->pix_mas * HOR;
	picture->img_ptr = mlx_new_image(all->win_str.mlx_ptr, HOR, VER);
	if (picture->img_ptr == NULL)
		exit(1);
	picture->pic_strt = 0;
	picture->img_mas = HOR * VER;
	picture->img_arr = (int *)mlx_get_data_addr(picture->img_ptr,
			&(picture->pix_mas), &(picture->line_mas), &(picture->pic_strt));
	if (picture->img_arr == NULL)
		exit (1);
	return (0);
}

t_num		transform_pix(int i)
{
	int			x;
	int			y;
	t_num		num;
	t_factor	fact;

	x = i % HOR;
	y = i / VER;
	fact.re_fact = ((MAXRE - MINRE) / (HOR - 1));
	fact.im_fact = ((MAXIM - MINIM) / (VER - 1));
	num.c_re = MINRE + (x * fact.re_fact);
	num.c_im = MAXIM - (y * fact.im_fact);
	return (num);
//это комплексное в функцию бросить и узнать цвет. и этот цвет записать в масив
}

void	change_px(t_pic *picture)
{
	int		i;
	t_num	num;;

	i = 0;
	while(i < picture->img_mas)
	{
		num = transform_pix(i);
		i++;
	}
}
