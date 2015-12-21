/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_rendering.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdos-san <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/16 16:25:03 by mdos-san          #+#    #+#             */
/*   Updated: 2015/12/21 08:50:40 by mdos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	key_hook(int keycode, t_par *par)
{
	if (keycode == 53)
	{
		mlx_destroy_window(par->mlx, par->win);
		exit (0);
	}
	if (keycode == 18)
	{
		par->coef++;
		get_pnt(par);
		par->angle_x = 45;
		par->angle_y = 0;
		par->angle_z = 45;
		par->img = 0;
		img_clear(par);
		draw(par);
		par->angle_x = 0;
		par->angle_y = 0;
		par->angle_z = 0;
	}
	if (keycode == 19)
	{
		par->coef--;
		get_pnt(par);
		par->angle_x = 45;
		par->angle_y = 0;
		par->angle_z = 45;
		par->img = 0;
		img_clear(par);
		draw(par);
		par->angle_x = 0;
		par->angle_y = 0;
		par->angle_z = 0;
	}
	if (keycode == 7)
	{
		par->angle_x = (par->angle_x == 0) ? 1 : 0;
		if (par->angle_x)
			ft_putendl("Rotation sur l'axe x : [ON]");
		else
			ft_putendl("Rotation sur l'axe x : [OFF]");
	}
	if (keycode == 16)
	{
		par->angle_y = (par->angle_y == 0) ? 1 : 0;
		if (par->angle_y)
			ft_putendl("Rotation sur l'axe y : [ON]");
		else
			ft_putendl("Rotation sur l'axe y : [OFF]");
	}
	if (keycode == 6)
	{
		par->angle_z = (par->angle_z == 0) ? 1 : 0;
		if (par->angle_z)
			ft_putendl("Rotation sur l'axe z : [ON]");
		else
			ft_putendl("Rotation sur l'axe z : [OFF]");
	}
	return (1);
}

int	expose_hook(t_par *par)
{
	mlx_put_image_to_window(par->mlx, par->win, par->img, 0, 0);
	return (0);
}

int	loop_hook(t_par *par)
{
	if (par->angle_x != 0 || par->angle_y != 0 || par->angle_z != 0)
	{
		img_clear(par);
		draw(par);
	}
	expose_hook(par);
	return (1);
}


void	start_rendering(t_par *par)
{
	par->mlx = mlx_init();
	par->win = mlx_new_window(par->mlx, WIDTH, HEIGHT, "mdos-san's fdf");
	par->angle_x = 45;
	par->angle_y = 0;
	par->angle_z = 45;
	par->img = 0;
	img_clear(par);
	draw(par);
	par->angle_x = 0;
	par->angle_y = 0;
	par->angle_z = 0;
	mlx_key_hook(par->win, key_hook, par);
	mlx_expose_hook(par->win, expose_hook, par);
	mlx_loop_hook(par->mlx, loop_hook, par);
	mlx_loop(par->mlx);
}
