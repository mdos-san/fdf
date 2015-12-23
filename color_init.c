/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdos-san <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/23 16:02:55 by mdos-san          #+#    #+#             */
/*   Updated: 2015/12/23 16:16:50 by mdos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	color_init(unsigned int *color, int value)
{
	int	r;
	int	g;
	int	b;

	b = (value > 255) ? 255 : value;
	value -= 255;
	g = (value > 255) ? 255 : value;
	value -= 255;
	r = (value > 255) ? 255 : value;
	*((unsigned char*)color + 0) = b;
	*((unsigned char*)color + 1) = g;
	*((unsigned char*)color + 2) = r;
	*((unsigned char*)color + 3) = 0;
}
