/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_rendering.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdos-san <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/16 16:25:03 by mdos-san          #+#    #+#             */
/*   Updated: 2015/12/17 18:45:28 by mdos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

int		loop_hook(t_par *par)
{
	if (par->i == WIDTH)
	{
		par->i = 0;
		img_clear(par);
	}
	img_put_pixel(par, par->i++, 10, GREEN);
	mlx_clear_window(par->mlx, par->win);
	mlx_put_image_to_window(par->mlx, par->win, par->img, 0, 0);
	ft_putendl("refresh");
	return (1);
}

void	start_rendering(void)
{
	t_par	*par;

	par = (t_par*)malloc(sizeof(t_par));
	par->mlx = mlx_init();
	par->win = mlx_new_window(par->mlx, WIDTH, HEIGHT, "test");
	par->img = mlx_new_image(par->mlx, WIDTH, HEIGHT);
	par->data = mlx_get_data_addr(par->img, &par->bpp, &par->sl, &par->ed);
	par->i = 0;
	mlx_loop_hook(par->mlx, loop_hook, par);
	mlx_loop(par->mlx);
}
