/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdos-san <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/17 19:05:26 by mdos-san          #+#    #+#             */
/*   Updated: 2015/12/17 19:18:43 by mdos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_vec	*vec_init(double x, double y, double z)
{
	t_vec	*new;

	new = (t_vec*)malloc(sizeof(t_vec));
	new->x = x;
	new->y = y;
	new->z = z;
	return (new);
}
