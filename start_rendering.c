/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_rendering.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdos-san <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/16 16:25:03 by mdos-san          #+#    #+#             */
/*   Updated: 2015/12/17 21:14:27 by mdos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

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

int	loop_hook(t_par *par)
{
	par->vx = vec_init(LEN, 0, 0);
	par->vy = vec_init(0, LEN, 0);
	par->vz = vec_init(0, 0, LEN);
	rotate_z(par, par->angle);
	par->angle = 90;
	par->img = mlx_new_image(par->mlx, WIDTH, HEIGHT);
	par->data = mlx_get_data_addr(par->img, &par->bpp, &par->sl, &par->ed);
	draw(par);
	mlx_put_image_to_window(par->mlx, par->win, par->img, 0, 0);
	mlx_destroy_image(par->mlx, par->img);
	return (1);
}

void	start_rendering(t_chain *chain)
{
	t_par	*par;

	par = (t_par*)malloc(sizeof(t_par));
	par->mlx = mlx_init();
	par->win = mlx_new_window(par->mlx, WIDTH, HEIGHT, "test");
	par->img = mlx_new_image(par->mlx, WIDTH, HEIGHT);
	par->data = mlx_get_data_addr(par->img, &par->bpp, &par->sl, &par->ed);
	par->chain = chain;
	ft_putnbr(par->chain->size);
	par->vx = vec_init(LEN, 0, 0);
	par->vy = vec_init(0, LEN, 0);
	par->vz = vec_init(0, 0, LEN);
	par->o = pnt_init((WIDTH - par->chain->size * LEN) / 2,
						(HEIGHT - chain_count(par->chain) * LEN) / 2, 0);
	mlx_loop_hook(par->mlx, loop_hook, par);
	mlx_key_hook(par->win, key_hook, par);
	mlx_loop(par->mlx);
}
