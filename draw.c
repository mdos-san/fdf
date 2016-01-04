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
		tmp.x = cur->pnt->x;
		tmp.y = cur->pnt->y;
		tmp.z = cur->pnt->z;
		pnt_translate(&tmp, par->rep->vx, fabs(cur->pnt->x), (cur->pnt->x > 0) ? 0 : 1);
		pnt_translate(&tmp, par->rep->vy, fabs(cur->pnt->y), (cur->pnt->y > 0) ? 0 : 1);
		pnt_translate(&tmp, par->rep->vz, fabs(cur->pnt->z), (cur->pnt->z > 0) ? 0 : 1);
		tmp.x += par->rep->origin.x;
		tmp.y += par->rep->origin.y;
		img_put_pixel(par, tmp, cur->pnt->color);
		cur = cur->next;
	}
	vec_draw(par, &par->rep->vx, BLUE);
	vec_draw(par, &par->rep->vy, GREEN);
	vec_draw(par, &par->rep->vz, RED);
}
