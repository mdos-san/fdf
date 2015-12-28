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
	t_pnt	tmp;
	t_grad	*grad;

	coef = (b.y - a.y) / (b.x - a.x);
	tmp.x = a.x;
	tmp.y = a.y;
	tmp.color = a.color;
	if (-1 <= coef && coef <= 1)
	{
		grad = get_grad(&b.color, &a.color, (b.x - a.x));
		while ((int)a.x != (int)b.x)
		{
			img_put_pixel(par, a, a.color);
			a.color = tmp.color;
			grad_apply(&a, *grad, b.x - a.x);
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
		grad = get_grad(&b.color, &a.color, (b.y - a.y));
		while ((int)a.y != (int)b.y)
		{
			img_put_pixel(par, a, a.color);
			a.color = tmp.color;
			grad_apply(&a, *grad, b.y - a.y);
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
	img_put_pixel(par, b, b.color);
}
