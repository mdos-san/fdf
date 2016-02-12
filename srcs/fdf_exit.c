/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_exit.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdos-san <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/12 02:49:07 by mdos-san          #+#    #+#             */
/*   Updated: 2016/02/12 02:59:00 by mdos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	fdf_exit(t_par *par)
{
	repere_del(&par->rep);
	chain_del(&par->chain);
	mlx_destroy_image(par->mlx, par->img);
	mlx_destroy_window(par->mlx, par->win);
	exit(0);
}
