/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_event.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdos-san <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/28 15:25:18 by mdos-san          #+#    #+#             */
/*   Updated: 2016/02/12 03:02:34 by mdos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		key_pr(int keycode, t_par *par)
{
	if (keycode == 0 || keycode == 100)
		par->angle_y = 2;
	if (keycode == 2 || keycode == 97)
		par->angle_y = -2;
	if (keycode == 13 || keycode == 115)
		par->angle_x = 2;
	if (keycode == 1 || keycode == 119)
		par->angle_x = -2;
	if (keycode == 12 || keycode == 113)
		par->angle_z = -2;
	if (keycode == 14 || keycode == 101)
		par->angle_z = 2;
	if (keycode == 65470 || keycode == 69)
		par->event_zoom = 1;
	if (keycode == 65471 || keycode == 78)
		par->event_zoom = -1;
	if (keycode == 65472 || keycode == 120)
		par->event_height = 1;
	if (keycode == 65473 || keycode == 122)
		par->event_height = -1;
	return (1);
}

int		key_rl(int keycode, t_par *par)
{
	if (keycode == 0 || keycode == 100)
		par->angle_y = 0;
	if (keycode == 2 || keycode == 97)
		par->angle_y = 0;
	if (keycode == 13 || keycode == 115)
		par->angle_x = 0;
	if (keycode == 1 || keycode == 119)
		par->angle_x = 0;
	if (keycode == 12 || keycode == 113)
		par->angle_z = 0;
	if (keycode == 14 || keycode == 101)
		par->angle_z = 0;
	if (keycode == 65470 || keycode == 78)
		par->event_zoom = 0;
	if (keycode == 65471 || keycode == 69)
		par->event_zoom = 0;
	if (keycode == 65472 || keycode == 120)
		par->event_height = 0;
	if (keycode == 65473 || keycode == 122)
		par->event_height = 0;
	if (keycode == 53 || keycode == 65307)
		fdf_exit(par);
	return (1);
}

void	key_event(t_par *par)
{
	mlx_hook(par->win, KEYPRESS, KEYPRESSMASK, key_pr, par);
	mlx_key_hook(par->win, key_rl, par);
}
