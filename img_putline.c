/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_putline->c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdos-san <marvin@42->fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/21 10:58:21 by mdos-san          #+#    #+#             */
/*   Updated: 2015/12/23 19:49:28 by mdos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
**y = a * x + p;
*/

void	img_putline(t_par *par, t_pnt *a, t_pnt *b)
{
	double	coef;
	double	p;
	int		diff;
	unsigned int	*grad;
	unsigned int	*colo;

	colo = a->color;
	coef = (b->y - a->y) / (b->x - a->x);
	p = a->y - (coef * a->x);
	if (-1 <= coef && coef <= 1)
	{
		diff = fabs(a->x - b->x);
		grad = color_getgradient(colo, b->color, diff);
		while ((int)a->x != (int)b->x)
		{
			a->y = a->x * coef + p;
			img_put_pixel(par, *a, *colo);
			color_add(colo, grad);
			if (a->x < b->x)
				a->x++;
			else
				a->x--;
		}
	}
	else
	{
		diff = fabs(a->y - b->y);
		grad = color_getgradient(colo, b->color, diff);
		while ((int)a->y != (int)b->y)
		{
			a->x = (a->y - p) / coef;
			img_put_pixel(par, *a, *colo);
			color_add(colo, grad);
			if (a->y < b->y)
				a->y++;
			else
				a->y--;
		}
	}
}
