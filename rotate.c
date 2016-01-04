/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdos-san <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/18 18:32:07 by mdos-san          #+#    #+#             */
/*   Updated: 2015/12/21 11:00:34 by mdos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	rotate_x(t_pnt *pnt, double angle)
{
	double	y;
	double	z;

	if (angle == 0)
		return ;
	angle = angle * M_PI / 180;
	y = pnt->y;
	z = pnt->z;
	pnt->y = y * cos(angle) - z * sin(angle);
	pnt->z = z * cos(angle) + y * sin(angle);
}

void	rotate_y(t_pnt *pnt, double angle)
{
	double	x;
	double	z;

	if (angle == 0)
		return ;
	angle = angle * M_PI / 180;
	x = pnt->x;
	z = pnt->z;
	pnt->x = x * cos(angle) - z * sin(angle);
	pnt->z = z * cos(angle) + x * sin(angle);
}

void	rotate_z(t_pnt *pnt, double angle)
{
	double	x;
	double	y;

	if (angle == 0)
		return ;
	angle = angle * M_PI / 180;
	x = pnt->x;
	y = pnt->y;
	pnt->x = x * cos(angle) - y * sin(angle);
	pnt->y = y * cos(angle) + x * sin(angle);
}
