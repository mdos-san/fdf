/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_rendering.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdos-san <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/16 16:25:03 by mdos-san          #+#    #+#             */
/*   Updated: 2015/12/18 18:03:26 by mdos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	key_hook(int keycode, t_par *par)
{
	if (keycode == 126)
		par->angle++;
	if (keycode == 125)
		par->angle--;
	if (keycode == 53)
		exit(0);
	return (1);
}


void	start_rendering(t_par *par)
{
	par->mlx = mlx_init();
	par->win = mlx_new_window(par->mlx, WIDTH, HEIGHT, "test");
	par->img = mlx_new_image(par->mlx, WIDTH, HEIGHT);
	par->data = mlx_get_data_addr(par->img, &par->bpp, &par->sl, &par->ed);
	draw(par);
	mlx_put_image_to_window(par->mlx, par->win, par->img, 0, 0);
	mlx_key_hook(par->win, key_hook, par);
	mlx_loop(par->mlx);
}
