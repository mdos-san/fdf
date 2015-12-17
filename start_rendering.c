/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_rendering.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdos-san <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/16 16:25:03 by mdos-san          #+#    #+#             */
/*   Updated: 2015/12/17 19:50:57 by mdos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

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
	par->o = pnt_init((WIDTH - par->chain->size * LEN) / 2,
						(HEIGHT - chain_count(par->chain) * LEN) / 2, 0);
	draw(par);
	mlx_put_image_to_window(par->mlx, par->win, par->img, 0, 0);
	mlx_loop(par->mlx);
}
