/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdos-san <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/12 02:16:29 by mdos-san          #+#    #+#             */
/*   Updated: 2016/02/12 02:17:23 by mdos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	color_init(t_color *color, unsigned char r,\
					unsigned char g, unsigned char b)
{
	color->r = r;
	color->g = g;
	color->b = b;
	color->a = 0;
}
