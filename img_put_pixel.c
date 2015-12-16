/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_put_pixel.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdos-san <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/16 17:10:13 by mdos-san          #+#    #+#             */
/*   Updated: 2015/12/16 18:20:01 by mdos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	img_put_pixel(void *mlx, t_img *img, t_pnt *pnt, int color)
{
	int		i;
	int		len;
	char	*data;

	i = -1;
	len = img->bits_per_pixel / 8;
	data = img->data + len * pnt->x + img->size_line * pnt->y;
	*(unsigned int *)(data) = mlx_get_color_value(mlx, color);
}
