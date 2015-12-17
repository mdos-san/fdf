/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pnt_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdos-san <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/17 19:24:36 by mdos-san          #+#    #+#             */
/*   Updated: 2015/12/17 19:27:40 by mdos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_pnt	*pnt_init(double x, double y, double z)
{
	t_pnt	*new;

	new = (t_pnt*)malloc(sizeof(t_pnt));
	new->x = x;
	new->y = y;
	new->z = z;
	return (new);
}
