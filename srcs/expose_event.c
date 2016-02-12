/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expose_event.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdos-san <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/28 15:46:13 by mdos-san          #+#    #+#             */
/*   Updated: 2016/02/12 02:17:56 by mdos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		expose_hook(t_par *par)
{
	img_clear(par);
	draw(par);
	mlx_put_image_to_window(par->mlx, par->win, par->img, 0, 0);
	return (0);
}

void	expose_event(t_par *par)
{
	mlx_expose_hook(par->win, expose_hook, par);
}
