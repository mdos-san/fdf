/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_putline.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdos-san <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/21 10:58:21 by mdos-san          #+#    #+#             */
/*   Updated: 2016/02/12 02:33:00 by mdos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	exeption(t_par *par, t_pnt a, t_pnt b)
{
	double coef;

	coef = (b.x - a.x) / (b.y - a.y);
	while ((int)a.y != (int)b.y)
	{
		img_put_pixel(par, a, color_convert(a.color));
		if (a.y < b.y)
		{
			a.x += coef;
			a.y++;
		}
		else
		{
			a.x -= coef;
			a.y--;
		}
	}
}

void		img_putline(t_par *par, t_pnt a, t_pnt b)
{
	double	coef;

	coef = (b.y - a.y) / (b.x - a.x);
	a.color = color_average(a.color, b.color);
	if (-1 <= coef && coef <= 1)
	{
		while ((int)a.x != (int)b.x)
		{
			img_put_pixel(par, a, color_convert(a.color));
			if (a.x < b.x)
			{
				a.y += coef;
				a.x++;
			}
			else
			{
				a.y -= coef;
				a.x--;
			}
		}
	}
	else
		exeption(par, a, b);
}
