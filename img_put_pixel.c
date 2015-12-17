/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_put_pixel.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdos-san <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/16 17:10:13 by mdos-san          #+#    #+#             */
/*   Updated: 2015/12/17 17:29:05 by mdos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	img_put_pixel(t_par *par, int x, int y, int color)
{
	*(unsigned int*)(par->data + x * par->bpp / 8 + par->sl * y) = mlx_get_color_value(par->mlx, color);
}
