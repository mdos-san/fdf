/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_new.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdos-san <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/30 15:22:06 by mdos-san          #+#    #+#             */
/*   Updated: 2015/12/30 15:36:55 by mdos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_vec	*vec_new(double x, double y, double z)
{
	t_vec	*new;

	new = (t_vec*)malloc(sizeof(t_vec));
	if (!new)
		return (NULL);
	new->x = x;
	new->y = y;
	new->z = z;
	return (new);
}
