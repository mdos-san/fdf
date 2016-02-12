/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_get.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdos-san <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/12 02:16:26 by mdos-san          #+#    #+#             */
/*   Updated: 2016/02/12 02:17:10 by mdos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_color	color_get(unsigned char r, unsigned char b,\
					unsigned char g, unsigned char a)
{
	t_color color;

	color.r = r;
	color.g = g;
	color.b = b;
	color.a = a;
	return (color);
}
