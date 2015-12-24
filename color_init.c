/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdos-san <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/23 16:02:55 by mdos-san          #+#    #+#             */
/*   Updated: 2015/12/23 19:36:24 by mdos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	color_init(unsigned int *color, int value)
{
	int	r;
	int	g;
	int	b;

	r = 0;
	g = 0;
	b = (value < 0) ? 100 : 0;
	if (0 <= value && value <= 10)
	{
		r = 255;
		g = 255;
	}
	if (10 < value && value <= 50)
		g = 255;
	if (50 < value && value <= 300)
	{
		r = 91;
		g = 60;
		b = 17;
	}
	if (300 < value)
	{
		r = 255;
		g = 255;
		b = 255;
	}
	*((unsigned char*)color + 0) = (b > 0) ? b : 0;
	*((unsigned char*)color + 1) = (g > 0) ? g : 0;
	*((unsigned char*)color + 2) = (r > 0) ? r : 0;
	*((unsigned char*)color + 3) = 0;
}
