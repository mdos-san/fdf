/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdos-san <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/17 20:18:05 by mdos-san          #+#    #+#             */
/*   Updated: 2015/12/17 21:08:16 by mdos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	rotate_x(t_par *par, double angle)
{
	angle = angle * M_PI / 180;
	par->vy->y = par->vy->y * cos(angle) - par->vy->z * sin(angle);
	par->vy->z = par->vy->y * sin(angle) + par->vy->z * cos(angle);
	par->vz->y = par->vz->y * cos(angle) - par->vz->z * sin(angle);
	par->vz->z = par->vz->y * sin(angle) + par->vz->z * cos(angle);
}

void	rotate_z(t_par *par, double angle)
{
	angle = angle * M_PI / 180;
	par->vx->x = par->vx->x * cos(angle) - par->vx->y * sin(angle);
	par->vx->y = par->vx->x * sin(angle) + par->vx->y * cos(angle);
	par->vy->x = par->vy->x * cos(angle) - par->vy->y * sin(angle);
	par->vy->y = par->vy->x * sin(angle) + par->vy->y * cos(angle);
}
