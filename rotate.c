/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdos-san <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/17 20:18:05 by mdos-san          #+#    #+#             */
/*   Updated: 2015/12/17 20:21:08 by mdos-san         ###   ########.fr       */
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
