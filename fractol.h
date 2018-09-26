/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiriuk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/12 16:36:24 by abiriuk           #+#    #+#             */
/*   Updated: 2018/09/20 20:27:05 by abiriuk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <math.h>


# define HOR 800
# define VER 800
# define MINRE -2.0
# define MAXRE 1.0
# define MINIM -1.2
# define MAXIM (MINIM + (MAXRE - MINRE) * VER / HOR);
# define REFACTOR ((MAXRE - MINRE) / (HOR - 1));
# define IMFACTOR ((MAXIM - MINIM) / (VER - 1));

typedef	struct		s_pixel
{
	int				x;
	int				y;
}					t_pixel;

typedef	struct		s_win
{
	void			*mlx_ptr;
	void			*win_ptr;
}					t_win;

typedef	struct		s_all
{
	t_win			win_str;
}					t_all;

typedef struct		s_pic
{
	int				pix_mas;
	int				line_mas;
	int				img_ptr;
	int				pic_strt;
	int				img_mas;
	int				*img_arr;
}					t_pic;

typedef	struct		s_num
{
	double			c_re;
	double			c_im;
}					t_num;

typedef	struct		s_fact
{
	double			re_fact;
	double			im_fact;
}					t_fact;

int					exit_x(void *par);
int					exit_esc(int keycode, void *param);
