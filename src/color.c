/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiriuk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/26 18:19:15 by abiriuk           #+#    #+#             */
/*   Updated: 2018/10/09 19:11:39 by abiriuk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		set_col(int res)
{
	int	color;
	if (res == ITTER)
		return (0x00520A5A);
	else if (res < ITTER / 18)
		return (0x00460A64);
	else if (res < ITTER / 15)
		return (0x00520A5A);
	else if (res < ITTER / 12)
		return (0x005F0A50);
	else if (res < ITTER / 8)
		return (0x006C0A46);
	else if (res < ITTER / 4)
		return (0x00790A3C);
	else if (res < ITTER / 2)
		return (0x00860A32);
	else if (res < ITTER / 1.5)
		return (0x00930A28);
	else
		color = res * 0x00FF6400 / ITTER;
	return (color);
}
