/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_pnt_color.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdos-san <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/28 12:43:50 by mdos-san          #+#    #+#             */
/*   Updated: 2016/02/12 02:18:25 by mdos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	get_pnt_color(t_par *par)
{
	int		min;
	int		length;
	t_chain	*cur;

	cur = par->chain;
	min = chain_min(cur);
	length = chain_max(cur) - chain_min(cur);
	while (cur)
	{
		cur->pnt->color = color_step(par->color1, par->color2,\
										length, cur->pnt->z - min);
		cur = cur->next;
	}
}
