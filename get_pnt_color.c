/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_pnt_color.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdos-san <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/28 12:43:50 by mdos-san          #+#    #+#             */
/*   Updated: 2015/12/28 12:57:53 by mdos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	get_pnt_color(t_par *par, unsigned int color1, unsigned int color2)
{
	int		i;
	int		min;
	int		length;
	t_grad	*grad;
	t_chain	*cur;

	cur = par->chain;
	min = chain_min(cur);
	i = min;
	length = chain_max(cur) - chain_min(cur);
	grad = get_grad(&color1, &color2, length);
	while (cur->next)
	{
		while (i < cur->pnt->z)
		{
			grad_apply(cur->pnt, *grad);
			++i;
		}
		i = min;
		cur = cur->next;
	}
}
