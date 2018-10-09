/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precision.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiriuk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/09 19:58:56 by abiriuk           #+#    #+#             */
/*   Updated: 2018/10/09 20:25:48 by abiriuk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		precision(int keycode, void *alli)
{
	t_all *all;

	all = (t_all *)alli;

	if (keycode == 69)
		all->itter += 5;
	else if (all->itter <= 5)
		return (0);
	else if (keycode == 78)
		all->itter -= 5;
	change_px(all->picture, all);
	return (0);
}
