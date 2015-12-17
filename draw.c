/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdos-san <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/17 19:03:46 by mdos-san          #+#    #+#             */
/*   Updated: 2015/12/17 20:23:55 by mdos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	translate_pnt(t_pnt *pnt, t_vec vec)
{
	pnt->x += vec.x;
	pnt->y += vec.y;
	pnt->z += vec.z;
}


void	draw(t_par *par)
{
	int		i;
	int		j;
	t_chain	*chain;
	t_pnt	pnt;
	t_pnt	tmp;

	i = 0;
	j = 0;
	chain = par->chain;
	pnt.x = par->o->x;
	pnt.y = par->o->y;
	while (chain)
	{
		while (i < chain->size)
		{
			tmp.x = pnt.x + par->vz->x * chain->tab[i] / (LEN / 2);
			tmp.y = pnt.y + par->vz->y * chain->tab[i] / (LEN / 2);
			if (chain->tab[i] != 0)
				img_put_pixel(par, tmp, RED);
			else
				img_put_pixel(par, tmp, WHITE);
			translate_pnt(&pnt, *par->vx);
			i++;
		}
		i = -1;
		j++;
		pnt.x = par->o->x;
		pnt.y = par->o->y;
		while (++i < j)
			translate_pnt(&pnt, *par->vy);
		i = 0;
		chain = chain->next;
	}
}
