/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_rendering.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdos-san <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/16 16:25:03 by mdos-san          #+#    #+#             */
/*   Updated: 2015/12/16 19:35:27 by mdos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	key_hook(int keycode, t_env *env)
{
	if (keycode == 53)
	{
		mlx_destroy_window(env->mlx, env->win);
		exit(0);
	}
	return (1);
}

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
	draw_test(env->mlx, chain, &pnt, img);
	mlx_put_image_to_window(env->mlx, env->win, img->img, 0, 0);
	mlx_key_hook(env->win, key_hook, env);
	mlx_loop(env->mlx);
}
