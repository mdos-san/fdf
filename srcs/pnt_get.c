/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pnt_get.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdos-san <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/12 02:19:36 by mdos-san          #+#    #+#             */
/*   Updated: 2016/02/12 02:19:39 by mdos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_pnt	pnt_get(double x, double y, double z)
{
	t_pnt	pnt;

	pnt.x = x;
	pnt.y = y;
	pnt.z = z;
	return (pnt);
}
