/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdos-san <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/17 19:03:46 by mdos-san          #+#    #+#             */
/*   Updated: 2015/12/30 17:48:59 by mdos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw(t_par *par)
{
	t_chain		*cur;
	t_pnt		tmp;

	cur = par->chain;
	vec_rotate_x(par->vx, par->angle_x);
	vec_rotate_x(par->vy, par->angle_x);
	vec_rotate_x(par->vz, par->angle_x);
	vec_rotate_y(par->vx, par->angle_y);
	vec_rotate_y(par->vy, par->angle_y);
	vec_rotate_y(par->vz, par->angle_y);
	vec_rotate_z(par->vx, par->angle_z);
	vec_rotate_z(par->vy, par->angle_z);
	vec_rotate_z(par->vz, par->angle_z);
	while (cur->next)
	{
		tmp.x = cur->pnt->x;
		tmp.y = cur->pnt->y;
		tmp.z = cur->pnt->z;
		pnt_translate(&tmp, *par->vx, cur->pnt->x);
		pnt_translate(&tmp, *par->vy, cur->pnt->y);
		pnt_translate(&tmp, *par->vz, cur->pnt->z);
		tmp.x += WIDTH / 2;
		tmp.y += HEIGHT / 2;
		img_put_pixel(par, tmp, WHITE);
		cur = cur->next;
	}
	vec_draw(par, par->vx, BLUE);
	vec_draw(par, par->vy, GREEN);
	vec_draw(par, par->vz, RED);
}
