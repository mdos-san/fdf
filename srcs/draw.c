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

static void	get_next_y(t_par *par, t_chain *chain)
{
	t_pnt	pnt;
	t_chain	*cur;
	int		i;

	i = 0;
	cur = chain;
	pnt = *cur->pnt;
	while (i < par->size_x)
	{
		cur = cur->next;
		i++;
	}
	img_putline(par, pnt, *cur->pnt);
}

static void	draw_line(t_par *par)
{
	t_chain	*cur;
	int		x;
	int		y;

	x = 0;
	y = 0;
	cur = par->chain;
	while (cur->next)
	{
		if (y < par->size_y - 1)
			get_next_y(par, cur);
		if (x < par->size_x - 1)
			img_putline(par, *cur->pnt, *cur->next->pnt);
		x++;
		if (x == par->size_x)
		{
			y++;
			x = 0;
		}
		cur = cur->next;
	}
}

void	draw(t_par *par)
{
	t_chain		*cur;

	cur = par->chain;
	repere_rotate_x(par->rep, par->angle_x);
	repere_rotate_y(par->rep, par->angle_y);
	repere_rotate_z(par->rep, par->angle_z);
	while (cur->next)
	{
		rotate_x(cur->pnt, par->angle_x, *par->rep);
		rotate_y(cur->pnt, par->angle_y, *par->rep);
		rotate_z(cur->pnt, par->angle_z, *par->rep);
		img_put_pixel(par, *cur->pnt, cur->pnt->color);
		cur = cur->next;
	}
	vec_draw(par, &par->rep->vx, BLUE);
	vec_draw(par, &par->rep->vy, GREEN);
	vec_draw(par, &par->rep->vz, RED);
	draw_line(par);
}
