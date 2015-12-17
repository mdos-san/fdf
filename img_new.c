/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_new.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdos-san <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/16 16:40:00 by mdos-san          #+#    #+#             */
/*   Updated: 2015/12/17 15:54:29 by mdos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_img	*img_new(void *mlx, int	width, int height)
{
	t_img	*new;

	new = (t_img*)malloc(sizeof(t_img));
	new->img = mlx_new_image(mlx, width, height);
	new->width = width;
	new->height = height;
	new->data = mlx_get_data_addr(new->img,
			&new->bits_per_pixel,
			&new->size_line,
			&new->endian);
	ft_putnbr(new->bits_per_pixel);
	ft_putendl("<= bits_per_pixel");
	ft_putnbr(new->size_line);
	ft_putendl("<= size_line");
	ft_putnbr(new->endian);
	ft_putendl("<= endian");
	return (new);
}
