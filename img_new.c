/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_new.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdos-san <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/16 16:40:00 by mdos-san          #+#    #+#             */
/*   Updated: 2015/12/16 16:48:14 by mdos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_img	*img_new(void *mlx, int	width, int height)
{
	t_img	*new;

	new = (t_img*)malloc(sizeof(t_env));
	new = mlx_new_image(mlx, width, height);
	new->width = width;
	new->height = height;
	return (new);
}
