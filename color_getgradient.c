/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_getgradient.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdos-san <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/23 15:55:27 by mdos-san          #+#    #+#             */
/*   Updated: 2015/12/23 16:47:22 by mdos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

unsigned int	*color_getgradient(unsigned int *color1, unsigned int *color2, int size)
{
	unsigned int	*gradient;

	gradient = color_new();
	if (size == 0)
		return (color1);
	*((unsigned char*)gradient + 0) = (*((unsigned char*)color1 + 0) - *((unsigned char*)color2 + 0)) / size;
	*((unsigned char*)gradient + 1) = (*((unsigned char*)color1 + 1) - *((unsigned char*)color2 + 1)) / size;
	*((unsigned char*)gradient + 2) = (*((unsigned char*)color1 + 2) - *((unsigned char*)color2 + 2)) / size;
	*((unsigned char*)gradient + 3) = (*((unsigned char*)color1 + 3) - *((unsigned char*)color2 + 3)) / size;
	return (gradient);
}
