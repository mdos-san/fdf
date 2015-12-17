/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdos-san <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/17 19:03:46 by mdos-san          #+#    #+#             */
/*   Updated: 2015/12/17 19:41:12 by mdos-san         ###   ########.fr       */
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
	t_pnt	pnt;
	t_pnt	tmp;
	t_vec	*x;
	t_vec	*y;
	t_vec	*z;

	i = 0;
	j = 0;
	pnt.x = par->o->x;
	pnt.y = par->o->y;
	x = vec_init(10, 0, 0);
	y = vec_init(0, 10, 0);
	z = vec_init(0, 0, 10);
	while (par->chain)
	{
		while (i < par->chain->size)
		{
			tmp.x = pnt.x + z->x * par->chain->tab[i];
			tmp.y = pnt.y + z->y * par->chain->tab[i];
			img_put_pixel(par, tmp, WHITE);
			translate_pnt(&pnt, *x);
			i++;
		}
		i = -1;
		j++;
		pnt.x = par->o->x;
		pnt.y = par->o->y;
		while (++i < j)
			translate_pnt(&pnt, *y);
		i = 0;
		par->chain = par->chain->next;
	}
}
