/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdos-san <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/17 19:03:46 by mdos-san          #+#    #+#             */
/*   Updated: 2015/12/18 19:06:49 by mdos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"


void	draw(t_par *par)
{
	t_chain	*cur;
	t_pnt	tmp;

	cur = par->chain;
	while (cur->next)
	{
		pnt_init(&tmp, cur->pnt->x, cur->pnt->y, cur->pnt->z);
		rotate_x(&tmp, par->angle_x);
		rotate_z(&tmp, par->angle_z);
		if (cur->pnt->z > 0)
			img_put_pixel(par, tmp, RED);
		else
			img_put_pixel(par, tmp, GREEN);
		cur = cur->next;
	}
}
