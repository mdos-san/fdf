/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pnt_new.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdos-san <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/18 15:45:59 by mdos-san          #+#    #+#             */
/*   Updated: 2015/12/28 11:38:19 by mdos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_pnt	*pnt_new(double x, double y, double z, t_color color)
{
	t_pnt	*new;

	new = (t_pnt*)malloc(sizeof(t_pnt));
	new->x = x;
	new->y = y;
	new->z = z;
	new->color = color;
	return (new);
}
