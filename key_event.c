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
	if (keycode == 65470)
		par->event_zoom = 1;
	if (keycode == 65471)
		par->event_zoom = -1;
	if (keycode == 65472)
		par->event_height = 1;
	if (keycode == 65473)
		par->event_height = -1;
	return (1);
}

int		key_rl(int keycode, t_par *par)
{
	ft_putnbr(keycode);
	ft_putchar('\n');
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
	if (keycode == 65470)
		par->event_zoom = 0;
	if (keycode == 65471)
		par->event_zoom = 0;
	if (keycode == 65472)
		par->event_height = 0;
	if (keycode == 65473)
		par->event_height = 0;
	if (keycode == 53 || keycode == 65307)
		exit (0);
	return (1);
}

void	key_event(t_par *par)
{
	mlx_hook(par->win, KeyPress, KeyPressMask, key_pr, par);
	mlx_key_hook(par->win, key_rl, par);
}
