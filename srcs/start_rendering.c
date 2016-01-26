/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_rendering.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdos-san <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/16 16:25:03 by mdos-san          #+#    #+#             */
/*   Updated: 2016/01/23 14:51:48 by mdos-san         ###   ########.fr       */
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
		parse(par);
	}
	if (par->event_height == -1)
	{
		par->coef -= 0.1;
		parse(par);
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
	img_clear(par);
	parse(par);
	key_event(par);
	expose_event(par);
	mlx_loop_hook(par->mlx, loop_hook, par);
	mlx_loop(par->mlx);
}
