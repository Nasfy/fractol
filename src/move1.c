/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiriuk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/10 17:15:24 by abiriuk           #+#    #+#             */
/*   Updated: 2018/10/10 17:35:45 by abiriuk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int     move_buf(int keycode, void *alli)
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
	change_buf(all->picture, all);
	return (0);
}
