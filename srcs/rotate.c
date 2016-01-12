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

void	rotate_x(t_pnt *pnt, double angle, t_rep rep)
{
	double	y;
	double	z;

	if (angle == 0)
		return ;
	pnt->y -= rep.origin.y;
	angle = angle * M_PI / 180;
	y = pnt->y;
	z = pnt->z;
	pnt->y = y * cos(angle) - z * sin(angle);
	pnt->z = z * cos(angle) + y * sin(angle);
	pnt->y += rep.origin.y;
}

void	rotate_y(t_pnt *pnt, double angle, t_rep rep)
{
	double	x;
	double	z;

	if (angle == 0)
		return ;
	angle = angle * M_PI / 180;
	pnt->x -= rep.origin.x;
	x = pnt->x;
	z = pnt->z;
	pnt->x = x * cos(angle) - z * sin(angle);
	pnt->z = z * cos(angle) + x * sin(angle);
	pnt->x += rep.origin.x;
}

void	rotate_z(t_pnt *pnt, double angle, t_rep rep)
{
	double	x;
	double	y;

	if (angle == 0)
		return ;
	angle = angle * M_PI / 180;
	pnt->x -= rep.origin.x;
	pnt->y -= rep.origin.y;
	x = pnt->x;
	y = pnt->y;
	pnt->x = x * cos(angle) - y * sin(angle);
	pnt->y = y * cos(angle) + x * sin(angle);
	pnt->x += rep.origin.x;
	pnt->y += rep.origin.y;
}
