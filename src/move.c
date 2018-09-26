/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiriuk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/26 18:53:13 by abiriuk           #+#    #+#             */
/*   Updated: 2018/09/26 19:52:51 by abiriuk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdio.h>

int		move(int keycode, void *alli)
{
	t_all *const all = (t_all *)alli;

	if (keycode == 124)
		all->move.x -= MOVE;
	else if (keycode == 123)
		all->move.x += MOVE;
	else if (keycode == 126)
		all->move.y += MOVE;
	else if (keycode == 125)
		all->move.y -= MOVE;
	change_px(all->picture, all);
	return (0);
}
