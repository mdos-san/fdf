/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_draw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdos-san <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/30 15:31:20 by mdos-san          #+#    #+#             */
/*   Updated: 2015/12/30 15:43:10 by mdos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	vec_draw(t_par *par, t_vec *vec, unsigned int color)
{
	t_pnt	a;
	t_pnt	b;

	a.x = WIDTH / 2;
	a.y = HEIGHT / 2;
	a.z = 0;
	a.color = color;
	b.x = a.x + vec->x;
	b.y = a.y + vec->y;
	b.z = a.z + vec->z;
	b.color = color;
	img_putline(par, a, b);
}
