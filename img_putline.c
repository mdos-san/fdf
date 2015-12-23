/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_putline.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdos-san <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/21 10:58:21 by mdos-san          #+#    #+#             */
/*   Updated: 2015/12/23 18:07:04 by mdos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
**y = a * x + p;
**
**
**
*/

void	img_putline(t_par *par, t_pnt a, t_pnt b)
{
	double	coef;
	double	p;

	par->color = (unsigned int*)malloc(sizeof(unsigned int));
	*((unsigned char*)(par->color) + 0) = 255; //BLU
	*((unsigned char*)(par->color) + 1) = 255;//vert
	*((unsigned char*)(par->color) + 2) = 100;//ROUGE
	*((unsigned char*)(par->color) + 3) = 100;//ALPHA
	coef = (b.y - a.y) / (b.x - a.x);
	p = a.y - (coef * a.x);
	if (-1 <= coef && coef <= 1)
		while ((int)a.x != (int)b.x)
		{
			a.y = a.x * coef + p;
		img_put_pixel(par, a, *par->color);
			if (a.x < b.x)
				a.x++;
			else
				a.x--;
		}
	else
		while ((int)a.y != (int)b.y)
		{
			a.x = (a.y - p) / coef;
			img_put_pixel(par, a, *par->color);
			if (a.y < b.y)
				a.y++;
			else
				a.y--;
		}
}
