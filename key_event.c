/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_event.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdos-san <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/28 15:25:18 by mdos-san          #+#    #+#             */
/*   Updated: 2015/12/28 17:08:17 by mdos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		key_pr(int keycode, t_par *par)
{
	if (keycode == 0)
		par->angle_y = 1;
	if (keycode == 2)
		par->angle_y = -1;
	if (keycode == 13)
		par->angle_x = 1;
	if (keycode == 1)
		par->angle_x = -1;
	if (keycode == 12)
		par->angle_z = -1;
	if (keycode == 14)
		par->angle_z = 1;
	if (keycode == 69)
		par->coef_add = 1;
	if (keycode == 78)
		par->coef_add = -1;
	return (1);
}

int		key_rl(int keycode, t_par *par)
{
	if (keycode == 0)
		par->angle_y = 0;
	if (keycode == 2)
		par->angle_y = 0;
	if (keycode == 13)
		par->angle_x = 0;
	if (keycode == 1)
		par->angle_x = 0;
	if (keycode == 12)
		par->angle_z = 0;
	if (keycode == 14)
		par->angle_z = 0;
	if (keycode == 69)
		par->coef_add = 0;
	if (keycode == 78)
		par->coef_add = 0;
	if (keycode == 53)
		exit (0);
	return (1);
}

void	key_event(t_par *par)
{
	mlx_hook(par->win, KeyPress, KeyPressMask, key_pr, par);
	mlx_key_hook(par->win, key_rl, par);
}
