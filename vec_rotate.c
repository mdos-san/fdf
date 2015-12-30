/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdos-san <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/30 15:47:29 by mdos-san          #+#    #+#             */
/*   Updated: 2015/12/30 15:53:34 by mdos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	vec_rotate_x(t_vec *vec, double angle)
{
	double	y;
	double	z;

	angle = angle * M_PI / 180;
	y = vec->y;
	z = vec->z;
	vec->y = y * cos(angle) - z * sin(angle);
	vec->z = z * cos(angle) + y * sin(angle);
}

void	vec_rotate_y(t_vec *vec, double angle)
{
	double	x;
	double	z;

	angle = angle * M_PI / 180;
	x = vec->x;
	z = vec->z;
	vec->x = x * cos(angle) - z * sin(angle);
	vec->z = z * cos(angle) + x * sin(angle);
}

void	vec_rotate_z(t_vec *vec, double angle)
{
	double	x;
	double	y;

	angle = angle * M_PI / 180;
	x = vec->x;
	y = vec->y;
	vec->x = x * cos(angle) - y * sin(angle);
	vec->y = y * cos(angle) + x * sin(angle);
}
