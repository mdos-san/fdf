/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_put_pixel.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdos-san <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/16 17:10:13 by mdos-san          #+#    #+#             */
/*   Updated: 2015/12/17 19:18:43 by mdos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	img_put_pixel(t_par *par, t_pnt pnt, int color)
{
	if ((0 < pnt.x && pnt.x < WIDTH) && (0 < pnt.y && pnt.y < HEIGHT))
		*(unsigned int*)(par->data + (int)(pnt.x) * par->bpp / 8 + par->sl * (int)(pnt.y)) = mlx_get_color_value(par->mlx, color);
}
