/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_putline.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdos-san <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/21 10:58:21 by mdos-san          #+#    #+#             */
/*   Updated: 2015/12/28 15:17:48 by mdos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	img_putline(t_par *par, t_pnt a, t_pnt b)
{
	double	coef;
	t_color	color;

	coef = (b.y - a.y) / (b.x - a.x);
	color = color_get(0, 0, 255, 0);
	if (-1 <= coef && coef <= 1)
	{
		while ((int)a.x != (int)b.x)
		{
			img_put_pixel(par, a, color_convert(color));
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
	{
		coef = (b.x - a.x) / (b.y - a.y);
		while ((int)a.y != (int)b.y)
		{
			img_put_pixel(par, a, color_convert(color));
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
}
