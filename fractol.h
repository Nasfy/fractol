/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiriuk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/12 16:36:24 by abiriuk           #+#    #+#             */
/*   Updated: 2018/10/09 21:11:36 by abiriuk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <math.h>
# include "mlx.h"


# define HOR 1200
# define VER 1200
# define MOVE 25

typedef	struct		s_win
{
	void			*mlx_ptr;
	void			*win_ptr;
}					t_win;

typedef struct		s_pic
{
	int				pix_mas;
	int				line_mas;
	void			*img_ptr;
	int				pic_strt;
	int				img_mas;
	int				*img_arr;
}					t_pic;

typedef	struct		s_num
{
	int				x;
	int				y;
	double			c_re;
	double			c_im;
}					t_num;

typedef	struct		s_start_end
{
	double			min_re;
	double			max_re;
	double			min_im;
	double			max_im;
}					t_start_end;

typedef	struct		s_all
{
	t_win			win_str;
	t_num			move;
	t_pic			*picture;
	t_start_end		zoom;
	t_num			mouse;
	t_num			fix;
	int				fix_num;
	int				itter;
}					t_all;

typedef	struct		s_fact
{
	double			re_fact;
	double			im_fact;
}					t_fact;



int					exit_x(void *par);
int					exit_esc(int keycode, void *param);
void				wind(t_all *all, t_pic *pic);
void				put_pix(int answer, t_num num, t_all *all);
int					mandelbrot(t_num num, int itter);
void				change_px(t_pic *picture, t_all *all);
int					set_col(int res, int itter);
int					move(int keycode, void *all);
int					mouse(int button, int x, int y, void *param);
int					motion(int x, int y, void *param);
t_num				transform_pix(int i, t_all *all);
void				change_mot(t_pic *picture, t_all *all);
void				change_clt(t_pic *picture, t_all *all);
int					move_clt(int keycode, void *alli);
void				change_clt(t_pic *picture, t_all *all);
int					mouse_clt(int button, int x, int y, void *param);
void				cover_clt(t_all *all, t_pic *pic);
void				cover_px(t_all *all, t_pic *pic);
void				change_hrt(t_pic *picture, t_all *all);
int					mouse_hrt(int button, int x, int y, void *param);
int					move_hrt(int keycode, void *alli);
void				cover_hrt(t_all *all, t_pic *pic);
int					precision(int keycode, void *alli);
int					mouse_jul(int button, int x, int y, void *param);
int					move_jul(int keycode, void *alli);

#endif
