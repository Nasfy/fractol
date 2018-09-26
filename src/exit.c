/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiriuk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/12 17:42:02 by abiriuk           #+#    #+#             */
/*   Updated: 2018/09/20 17:27:55 by abiriuk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

int     exit_x(void *par)
{
	 par = NULL;
 exit(1);
 return (0);
 }

int     exit_esc(int keycode, void *param)
{
	 param = NULL;
 	if (keycode == 53)
		 exit(1);
 	return (0);
 }
