/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_clear.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdos-san <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/17 18:42:54 by mdos-san          #+#    #+#             */
/*   Updated: 2015/12/18 18:39:37 by mdos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	img_clear(t_par *par)
{
	if (par->img)
		mlx_destroy_image(par->mlx, par->img);
	par->img = mlx_new_image(par->mlx, WIDTH, HEIGHT);
	par->data = mlx_get_data_addr(par->img, &par->bpp, &par->sl, &par->ed);
}
