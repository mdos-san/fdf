/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_convert.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdos-san <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/12 02:16:20 by mdos-san          #+#    #+#             */
/*   Updated: 2016/02/12 02:16:21 by mdos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

unsigned int	color_convert(t_color color)
{
	unsigned int	converted;

	*((unsigned char*)&converted + 0) = color.g;
	*((unsigned char*)&converted + 1) = color.b;
	*((unsigned char*)&converted + 2) = color.r;
	*((unsigned char*)&converted + 3) = color.a;
	return (converted);
}
