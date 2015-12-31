/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_rendering.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdos-san <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/16 16:25:03 by mdos-san          #+#    #+#             */
/*   Updated: 2015/12/30 18:16:49 by mdos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	loop_hook(t_par *par)
{
	if (par->event_zoom == 1)
	{
		vec_multiply(par->vx, 1.1);
		vec_multiply(par->vy, 1.1);
		vec_multiply(par->vz, 1.1);
	}
	if (par->event_zoom == -1)
	{
		vec_multiply(par->vx, 0.9);
		vec_multiply(par->vy, 0.9);
		vec_multiply(par->vz, 0.9);
	}
	if (par->event_height == 1)
		vec_multiply(par->vz, 1.1);
	if (par->event_height == -1)
		vec_multiply(par->vz, 0.9);
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
	par->color1 = BLUE;
	par->color2 = RED;
	par->coef = 1;
	par->vx = vec_new(1, 0, 0);
	par->vy = vec_new(0, 1, 0);
	par->vz = vec_new(0, 0, 1);
	img_clear(par);
	get_pnt(par, par->color1, par->color2);
	draw(par);
	key_event(par);
	expose_event(par);
	mlx_loop_hook(par->mlx, loop_hook, par);
	mlx_loop(par->mlx);
}
