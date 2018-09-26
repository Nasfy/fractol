/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiriuk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/26 18:19:15 by abiriuk           #+#    #+#             */
/*   Updated: 2018/09/26 18:52:58 by abiriuk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		set_col(int res)
{
	int	color;
	if (res == ITTER)
		return (0);
	else if (res < ITTER / 2)
		return (0);
	else
		color = res * 255 / ITTER;
	return (color);
}
