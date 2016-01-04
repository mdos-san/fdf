/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdos-san <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/17 19:03:46 by mdos-san          #+#    #+#             */
/*   Updated: 2015/12/30 18:18:36 by mdos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw(t_par *par)
{
	t_chain		*cur;
	t_pnt		tmp;

	cur = par->chain;
	repere_rotate_x(par->rep, par->angle_x);
	repere_rotate_y(par->rep, par->angle_y);
	repere_rotate_z(par->rep, par->angle_z);
	while (cur->next)
	{
		rotate_x(cur->pnt, par->angle_x);
		rotate_y(cur->pnt, par->angle_y);
		rotate_z(cur->pnt, par->angle_z);
		tmp = *cur->pnt;
		tmp.x += par->rep->origin.x;
		tmp.y += par->rep->origin.y;
		tmp.z += par->rep->origin.z;
		img_put_pixel(par, tmp, cur->pnt->color);
		cur = cur->next;
	}
	vec_draw(par, &par->rep->vx, BLUE);
	vec_draw(par, &par->rep->vy, GREEN);
	vec_draw(par, &par->rep->vz, RED);
}
