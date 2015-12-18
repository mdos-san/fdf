/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_rendering.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdos-san <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/16 16:25:03 by mdos-san          #+#    #+#             */
/*   Updated: 2015/12/18 19:15:48 by mdos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	loop_hook(t_par *par)
{
	img_clear(par);
	par->angle_x = 0.5;
	par->angle_y = 0.5;
	par->angle_z = 0.5;
	draw(par);
	mlx_put_image_to_window(par->mlx, par->win, par->img, 0, 0);
	return (1);
}


void	start_rendering(t_par *par)
{
	par->mlx = mlx_init();
	par->win = mlx_new_window(par->mlx, WIDTH, HEIGHT, "test");
	par->angle_x = 0;
	par->angle_y = 0;
	par->angle_z = 0;
	par->img = 0;
	mlx_loop_hook(par->mlx, loop_hook, par);
	mlx_loop(par->mlx);
}
