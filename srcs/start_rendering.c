/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_rendering.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdos-san <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/16 16:25:03 by mdos-san          #+#    #+#             */
/*   Updated: 2016/01/23 11:56:21 by mdos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	loop_hook(t_par *par)
{
	if (par->event_zoom == 1)
	{
		vec_multiply(&par->rep->vx, 1.1);
		vec_multiply(&par->rep->vy, 1.1);
		vec_multiply(&par->rep->vz, 1.1);
		chain_zoom(par->chain, 1.1, *par->rep);
	}
	if (par->event_zoom == -1)
	{
		vec_multiply(&par->rep->vx, 0.9);
		vec_multiply(&par->rep->vy, 0.9);
		vec_multiply(&par->rep->vz, 0.9);
		chain_zoom(par->chain, 0.9, *par->rep);
	}
	if (par->event_height == 1)
	{
		par->coef += 0.1;
		get_pnt(par, par->color1, par->color2);
	}
	if (par->event_height == -1)
	{
		par->coef -= 0.1;
		get_pnt(par, par->color1, par->color2);
	}
	expose_hook(par);
	return (1);
}

void	start_rendering(t_par *par)
{
	par->mlx = mlx_init();
	par->win = mlx_new_window(par->mlx, WIDTH, HEIGHT, "mdos-san's fdf");
	par->img = NULL;
	par->angle_x = 0;
	par->angle_y = 0;
	par->angle_z = 0;
	par->color1 = RED;
	par->color2 = BLUE;
	par->coef = 1;
	par->rep = repere_new(vec_get(1, 0, 0),
							vec_get(0, 1, 0),
							vec_get(0, 0, 1),
							pnt_get(WIDTH / 2, HEIGHT / 2, 0));
	img_clear(par);
	get_pnt(par, par->color1, par->color2);
	draw(par);
	key_event(par);
	expose_event(par);
	mlx_loop_hook(par->mlx, loop_hook, par);
	mlx_loop(par->mlx);
}
