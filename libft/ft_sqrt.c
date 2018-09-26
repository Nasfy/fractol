/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiriuk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 12:57:19 by abiriuk           #+#    #+#             */
/*   Updated: 2017/11/29 13:01:49 by abiriuk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt(int nb)
{
	int i;
	int g;

	i = 1;
	while (nb > 0 && i * i <= nb)
	{
		g = i * i;
		if (g == nb)
			return (i);
		else if (g > nb)
			return (0);
		else
			i++;
	}
	return (0);
}
