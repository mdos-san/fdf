/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_rendering.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdos-san <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/16 16:25:03 by mdos-san          #+#    #+#             */
/*   Updated: 2015/12/16 18:07:52 by mdos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	start_rendering(t_chain *chain)
{
	t_env	*env;
	t_img	*img;
	t_pnt	pnt;

	pnt.x = 200;
	pnt.y = 200;
	env = (t_env*)malloc(sizeof(t_env));
	env->mlx = mlx_init();
	env->win = mlx_new_window(env->mlx, WIDTH, HEIGHT, "mdos-san's fdf");
	img = img_new(env->mlx, WIDTH, HEIGHT);
	img_put_pixel(env->mlx, img, &pnt, 0xFFFFFF);
	mlx_put_image_to_window(env->mlx, env->win, img->img, 0, 0);

	ft_putnbr(img->bits_per_pixel);
	chain_count(chain);
	mlx_loop(env->mlx);
}
