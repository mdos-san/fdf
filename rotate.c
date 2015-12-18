/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdos-san <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/18 18:32:07 by mdos-san          #+#    #+#             */
/*   Updated: 2015/12/18 19:10:50 by mdos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	rotate_x(t_pnt *pnt, double angle)
{
	double	y;
	double	z;

	angle = angle * M_PI / 180;

	pnt->y -= HEIGHT / 2;
	y = pnt->y;
	z = pnt->z;
	pnt->y = y * cos(angle) - z * sin(angle);
	pnt->z = z * cos(angle) + y * sin(angle);
	pnt->y += HEIGHT / 2;
}

void	rotate_z(t_pnt *pnt, double angle)
{
	double	x;
	double	y;

	angle = angle * M_PI / 180;

	pnt->x -= WIDTH / 2;
	pnt->y -= HEIGHT / 2;
	x = pnt->x;
	y = pnt->y;
	pnt->x = x * cos(angle) - y * sin(angle);
	pnt->y = y * cos(angle) + x * sin(angle);
	pnt->x += WIDTH / 2;
	pnt->y += HEIGHT / 2;
}
